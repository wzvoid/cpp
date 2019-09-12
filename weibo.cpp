#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void permutation(vector<vector<int>> &arry, vector<int> &nums, int start, int end) {
    if (start == end) {
        vector<int> temp;
        for (int i = 0; i <= end; ++i) {
            temp.push_back(nums[i]);
        }
        arry.push_back(temp);
    } else {
        for (int i = start; i <= end; ++i) {
            swap(nums[start], nums[i]);
            permutation(arry, nums, start + 1, end);
            swap(nums[start], nums[i]);
        }
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> permut;
    permutation(permut, nums, 0, nums.size() - 1);
    return permut;
}

int main() {
    int n;
    cin >> n;
    vector<int> A, P;
    for (int i = 0; i < n - 1; ++i) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    for (int j = 0; j < n; ++j) {
        P.push_back(j + 1);
    }
    vector<vector<int>> pp = permute(P);
    int count = 0;
    for (int k = 0; k < pp.size(); ++k) {
        vector<int> temp = pp[k];
        int flag = 1;
        for (int i = 0; i < A.size(); ++i) {
            if ((A[i] == 0 && temp[i] < temp[i + 1]) || (A[i] == 1 && temp[i] > temp[i + 1]))
                continue;
            else {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            ++count;
    }
    cout << (count % (int) (pow(10, 9) + 7));
}