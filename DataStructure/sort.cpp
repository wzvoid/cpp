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
    // 插入排序
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

    // 选择排序
    void selectSort(vector<int> &arr) {
        if (!arr.empty()) {
            int end = arr.size() - 1;
            for (int i = 0; i < end; ++i) {
                int k = i; // 用指针指向最小值，这里假使 k 指向最小值。
                for (int j = k + 1; j <= end; ++j) // 因为每次都要进循环里面，所以最好最坏平均都是O(n^2)
                    if (arr[j] < arr[k])
                        k = j;
                if (k != i) { //这边不要盲目交换
                    int temp = arr[k];
                    arr[k] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }

    // 堆排序
    // 调整堆，也就是调整某个节点 i
    void adjustHeap(vector<int> &arr, int i, int end) {
        if (!arr.empty()) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left <= end && arr[left] > arr[i]) {// 再调整左子树
                swap(arr[i], arr[left]); // 利用algorithm中的swap函数
                adjustHeap(arr, left, end);
            }
            if (right <= end && arr[right] > arr[i]) {// 先调整右子树
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
//    		int temp = arr[i]; //记录当前节点
//    		for (int k = 2 * i + 1; k <= end; k = 2 * k + 1) { // 一直沿着左子树遍历
//    			if ((k + 1) <= end && arr[k + 1] > arr[k]) { // 如果有右节点，且右节点比左节点还大
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
            int end = arr.size() - 1; // end就是用来防止越界的

            // 从最后一个非叶节点开始,构建一个初始堆。
            for (int i = (end - 1) / 2; i >= 0; --i) {
                adjustHeap(arr, i, end);
            }

            // 交换堆顶元素与最后一个元素，然后继续调整除最后一个元素以外剩下的部分。
            // 为什么adjustHeap()只执行一次呢？因为此时只有堆顶元素有可能是不满足堆的性质的。
            for (int j = end; j >= 1; --j) {
                swap(arr[0], arr[j]);
                adjustHeap(arr, 0, j - 1);
            }
        }
    }

    // 快速排序O(nlogn)
    void quickSort(int *arr, int i, int j) {// 全部都是 < 号,处处判断 start < end
        if (i < j) {
            int start = i, end = j;
            int temp = arr[start];
            while (start < end) {
                while (start < end && arr[end] > temp)
                    --end;
                if (start < end) { // 这边也要加上 if 判断
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
            arr[start] = temp; // 这边 end 也可以
            quickSort(arr, i, start - 1);
            quickSort(arr, start + 1, j);
        }
    }

    // 归并排序：最好，最坏，平均时间复杂度均为O(nlogn)
    void mergearray(int *a, int first, int mid, int last, int *temp) {
        int i = first, j = mid + 1;
        int k = 0;
        while (i <= mid && j <= last) {
            if (a[i] <= a[j])
                temp[k++] = a[i++];
            else
                temp[k++] = a[j++];
        }
        while (i <= mid) temp[k++] = a[i++]; // 将左边剩余元素填充进temp中
        while (j <= last) temp[k++] = a[j++]; // 将右边剩余元素填充进temp中
        for (i = 0; i < k; i++) //将temp中的元素全部拷贝到原数组中
            a[first + i] = temp[i];
    }

    void mergesort(int *a, int first, int last, int *temp) //在排序前，先建好一个长度等于原数组长度的临时数组，避免递归中频繁开辟空间
    {
        if (first < last) {
            int mid = (first + last) / 2;
            mergesort(a, first, mid, temp);    //左边有序
            mergesort(a, mid + 1, last, temp); //右边有序
            mergearray(a, first, mid, last, temp); //再将二个有序数列合并
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