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
    // ��������
    // void insertSort(int *arr, int n)
    void insertSort(vector<int> &arr) {
        if (!arr.empty()) {
            int end = arr.size() - 1;
            for (int i = 1; i <= end; ++i) {
                int j = i - 1, temp = arr[i];
                while (j >= 0 && temp < arr[j]) {
                    arr[j + 1] = arr[j];
                    --j;
                }
                arr[j + 1] = temp;
            }
        }
    }

    // ѡ������
    void selectSort(vector<int> &arr) {
        if (!arr.empty()) {
            int end = arr.size() - 1;
            for (int i = 0; i < end; ++i) {
                int k = i; // ��ָ��ָ����Сֵ�������ʹ k ָ����Сֵ��
                for (int j = k + 1; j <= end; ++j) // ��Ϊÿ�ζ�Ҫ��ѭ�����棬��������ƽ������O(n^2)
                    if (arr[j] < arr[k])
                        k = j;
                if (k != i) { //��߲�ҪäĿ����
                    int temp = arr[k];
                    arr[k] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }

    // ������
    // �����ѣ�Ҳ���ǵ���ĳ���ڵ� i
    void adjustHeap(vector<int> &arr, int i, int end) {
        if (!arr.empty()) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left <= end && arr[left] > arr[i]) {// �ٵ���������
                swap(arr[i], arr[left]); // ����algorithm�е�swap����
                adjustHeap(arr, left, end);
            }
            if (right <= end && arr[right] > arr[i]) {// �ȵ���������
                swap(arr[i], arr[right]);
                adjustHeap(arr, right, end);
            }
        }
    }

//    void adjustHeap(vector<int> &arr, int i, int end) {
//    	if (arr.size() > 0) {
//    		for (int k = 2 * i + 1; k <= end; k = 2 * k + 1) {
//    			if ((k + 1) <= end && arr[k + 1] > arr[k]) {
//    				++k;
//    			}
//    			if (arr[k] > arr[i]) {
//    				swap(arr, i, k);
//    				i = k;
//    			}
//    			else {
//    				break;
//    			}
//    		}
//    	}
//    }
//
//    void adjustHeap(vector<int> &arr, int i, int end) {
//    	if (arr.size() > 0) {
//    		int temp = arr[i]; //��¼��ǰ�ڵ�
//    		for (int k = 2 * i + 1; k <= end; k = 2 * k + 1) { // һֱ��������������
//    			if ((k + 1) <= end && arr[k + 1] > arr[k]) { // ������ҽڵ㣬���ҽڵ����ڵ㻹��
//    				++k;
//    			}
//    			if (arr[k] > temp) {
//    				arr[i] = arr[k];
//    				i = k;
//    			}
//    			else {
//    				break;
//    			}
//    		}
//    		arr[i] = temp;
//    	}
//    }
//
//        void adjustHeap(int[] arr, int i, int end) {
//            if (arr.length > 0) {
//                while ((2 * i + 1) <= end) {
//                    int k = 2 * i + 1;
//                    if ((k + 1) <= end && arr[k + 1] > arr[k]) {
//                        ++k;
//                    }
//                    if (arr[k] > arr[i]) {
//                        swap(arr, i, k);
//                        i = k;
//                    } else {
//                        break;
//                    }
//                }
//            }
//        }

    void heapSort(vector<int> &arr) {
        if (!arr.empty()) {
            int end = arr.size() - 1; // end����������ֹԽ���

            // �����һ����Ҷ�ڵ㿪ʼ,����һ����ʼ�ѡ�
            for (int i = (end - 1) / 2; i >= 0; --i) {
                adjustHeap(arr, i, end);
            }

            // �����Ѷ�Ԫ�������һ��Ԫ�أ�Ȼ��������������һ��Ԫ������ʣ�µĲ��֡�
            // ΪʲôadjustHeap()ִֻ��һ���أ���Ϊ��ʱֻ�жѶ�Ԫ���п����ǲ�����ѵ����ʵġ�
            for (int j = end; j >= 1; --j) {
                swap(arr[0], arr[j]);
                adjustHeap(arr, 0, j - 1);
            }
        }
    }

    // ��������O(nlogn)
    void quickSort(int *arr, int i, int j) {// ȫ������ < ��,�����ж� start < end
        if (i < j) {
            int start = i, end = j;
            int temp = arr[start];
            while (start < end) {
                while (start < end && arr[end] > temp)
                    --end;
                if (start < end) { // ���ҲҪ���� if �ж�
                    arr[start] = arr[end];
                    ++start;
                }
                while (start < end && arr[start] < temp)
                    ++start;
                if (start < end) {
                    arr[end] = arr[start];
                    --end;
                }
            }
            arr[start] = temp; // ��� end Ҳ����
            quickSort(arr, i, start - 1);
            quickSort(arr, start + 1, j);
        }
    }

    // �鲢������ã����ƽ��ʱ�临�ӶȾ�ΪO(nlogn)
    void mergearray(int *a, int first, int mid, int last, int *temp) {
        int i = first, j = mid + 1;
        int k = 0;
        while (i <= mid && j <= last) {
            if (a[i] <= a[j])
                temp[k++] = a[i++];
            else
                temp[k++] = a[j++];
        }
        while (i <= mid) temp[k++] = a[i++]; // �����ʣ��Ԫ������temp��
        while (j <= last) temp[k++] = a[j++]; // ���ұ�ʣ��Ԫ������temp��
        for (i = 0; i < k; i++) //��temp�е�Ԫ��ȫ��������ԭ������
            a[first + i] = temp[i];
    }

    void mergesort(int *a, int first, int last, int *temp) //������ǰ���Ƚ���һ�����ȵ���ԭ���鳤�ȵ���ʱ���飬����ݹ���Ƶ�����ٿռ�
    {
        if (first < last) {
            int mid = (first + last) / 2;
            mergesort(a, first, mid, temp);    //�������
            mergesort(a, mid + 1, last, temp); //�ұ�����
            mergearray(a, first, mid, last, temp); //�ٽ������������кϲ�
        }
    }
};

int main() {
    Solution s;
    vector<int> v{5, 3, 8, 1, 7, 0};
    s.heapSort(v);
    for (auto c:v)
        cout << c << " ";
    return 0;
}