//
// Created by 王振 on 2019-06-22.
//
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<list>
#include<memory>
#include <cctype>
#include<unordered_map>

using namespace std;

class Solution {
public:
//    5 3 8 1 7 0
    void insertSort(vector<int> &arr) {
        if (!arr.empty()) {
            int arr_size = arr.size();
            for (int i = 1; i < arr_size; ++i) {
                int j = i;
                int temp = arr[j];
                while (j > 0 && arr[j - 1] > temp) {
                    arr[j] = arr[j - 1];
                    --j;
                }
                arr[j] = temp;
            }
        }
    }

    void selectSort(vector<int> &arr) {
        if (!arr.empty()) {
            int arr_size = arr.size();
            for (int i = 0; i < arr_size; ++i) {
                int k = i;
                for (int j = i + 1; j < arr_size; ++j) {
                    if (arr[j] < arr[k])
                        k = j;
                }
                if (k != i)
                    swap(arr[i], arr[k]);
            }
        }
    }

//    void adjustHeap(vector<int> &arr, int i, int end) {
//        if (!arr.empty()) {
//            int left = 2 * i + 1, right = 2 * i + 2;
//            if (right <= end && arr[i] < arr[right]) {
//                swap(arr[i], arr[right]);
//                adjustHeap(arr, right, end);
//            }
//            if (left <= end && arr[i] < arr[left]) {
//                swap(arr[i], arr[left]);
//                adjustHeap(arr, left, end);
//            }
//
//        }
//    }

    void adjustHeap(vector<int> &arr, int i, int end) {
        if (!arr.empty()) {
//            int temp = arr[i];
            while ((2 * i + 1) <= end) {
                int k = 2 * i + 1;
                if ((k + 1) <= end && arr[k] < arr[k + 1]) {
                    ++k;
                }
                if (arr[k] > arr[i]) {
                    swap(arr[k], arr[i]);
//                    arr[i] = arr[k];
                    i = k;
                } else break;
            }
//            arr[i] = temp;
        }
    }

    void heapSort(vector<int> &arr) {
        if (!arr.empty()) {
            int end = arr.size() - 1;
            for (int i = (end - 1) / 2; i >= 0; --i) {
                adjustHeap(arr, i, end);
            }
            for (int i = end; i >= 0; --i) {
                swap(arr[0], arr[i]);
                adjustHeap(arr, 0, i - 1);
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> v{5, 3, 8, 1, 7, 0, 8, 1};
    s.heapSort(v);
    for (auto c:v)
        cout << c << " ";
    return 0;
}
