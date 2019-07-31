//
// Created by 王振 on 2019-07-29.
// 旋转数组的最小数字

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//int minNumberInRotateArray(vector<int> rotateArray) {
//    if (rotateArray.empty()) {
//        return 0;
//    }
//    int end = rotateArray.size() - 1;
//    int i = 1;
//    while (i <= end && rotateArray[i] >= rotateArray[i - 1])
//        ++i;
//    return rotateArray[i];
//}

// 1, 2, 3, 4, 5, 6, 7, 8
// 6, 7, 8, 1, 2, 3, 4, 5
// 8, 1, 2, 3, 4, 5, 6, 7
int minNumberInRotateArray(vector<int> rotateArray) {
    int left = 0, right = rotateArray.size() - 1;
    if (rotateArray[left] < rotateArray[right])
        return rotateArray[left];
    int mid = -1;
    while (left < right) {
        mid = (left + right) / 2;
        if (rotateArray[left] < rotateArray[mid])
            left = mid + 1;
        else if (rotateArray[mid] < rotateArray[right])
            right = mid - 1;
        else
            return rotateArray[mid];
    }
    return INT32_MIN;
}

int main() {
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> v2{6, 7, 8, 1, 2, 3, 4, 5};
    vector<int> v3{8, 1, 2, 3, 4, 5, 6, 7};
    cout << minNumberInRotateArray(v3);
    return 0;
}