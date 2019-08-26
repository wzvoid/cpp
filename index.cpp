#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <set>

using namespace std;

void reverseString(vector<char> &s) {
    if (s.empty()) {
        return;
    }
//    vector<char>::iterator start = s.begin(), end = s.end() - 1;
    int start = 0, end = s.size() - 1;
    while (start < end) {
        char c = s[start];
        s[start] = s[end];
        s[end] = c;
        ++start;
        --end;
    }
}

void moveZeroes(vector<int> &nums) {
    // 16%
    // if(nums.size() >= 2) {
    //     for (int i = 1; i < nums.size(); ++i) {
    //         if (nums[i] != 0) {
    //             int temp = nums[i];
    //             int j = i - 1;
    //             while (j >= 0 && nums[j] == 0) {
    //                 nums[j + 1] = nums[j];
    //                 --j;
    //             }
    //             nums[j + 1] = temp;
    //         }
    //     }
    // }

    // 56%
//    if (nums.size() >= 2) {
//        for (int i = 0, j = 0; j < nums.size(); ++j) {
//            if (nums[i] != 0)
//                ++i;
//            else {
//                if (i != j && nums[j] != 0) {
//                    swap(nums[i], nums[j]);
//                    ++i;
//                }
//            }
//        }
//    }

//    [0, 1, 0, 3, 12]
//1 0 0 3 12
//1 3 0 0 12
    if (nums.size() > 1) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            while (i < nums.size() && nums[i] != 0) ++i;
            j = i + 1;
            while (j < nums.size() && nums[j] == 0) ++j;
            if (j < nums.size()) {
                swap(nums[i], nums[j]);
                for (auto &c:nums)
                    cout << c << " ";
                cout << endl;
                i++;
//                j = i + 1;
            }
        }
    }
}

int main() {
//    vector<int> v{5, 3, 8, 1, 7, 0, 0};
//    for (vector<int>::size_type i = 0; i < v.size() - 1; ++i) {
//        for (vector<int>::size_type j = 0; j < v.size() - 1 - i; ++j) {
//            if (v[j] > v[j + 1])
//                swap(v[j], v[j + 1]);
//        }
//    }
//    for (auto &c:v)
//        cout << c << " ";
    vector<int> v{0, 1, 0, 3, 12};
    moveZeroes(v);
    for (auto &c:v)
        cout << c << " ";
    char *r = nullptr;
    return 0;
}