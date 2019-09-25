//
// Created by 王振 on 2019/9/21.
//

#include<iostream>
#include <vector>

using namespace std;

void quickSort(vector<vector<int>> array, int left, int right) {
    if (array.empty() || left >= right || array.size() <= 1)
        return;
    vector<int> temp = array[left];
    while (right > left) {
        while (left < right) {
            if (temp[1] < array[right][1]) {
                --right;
                continue;
            }
            if (temp[1] > array[right][1]) {
                break;
            }
            if (temp[0] <= array[right][0]) {
                --right;
            } else {
                break;
            }
        }
        if (left < right) {
            array[left][0] = array[right][0];
            array[left][1] = array[right][1];
            ++left;
        }
        while (left < right) {
            if (temp[1] > array[left][1]) {
                ++left;
                continue;
            }
            if (temp[1] < array[left][1]) {
                break;
            }
            if (temp[0] >= array[left][0]) {
                ++left;
            } else {
                break;
            }
        }
        if (left < right) {
            array[right][0] = array[left][0];
            array[right][1] = array[left][1];
            --right;
        }
    }
    array[left][0] = temp[0];
    array[left][1] = temp[1];
    int mid = left;
    quickSort(array, left, mid);
    quickSort(array, mid + 1, right);

}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; ++i) {
        int height, width;
        cin >> height >> width;
        vector<int> temp;
        if (height > width) {
            temp.push_back(width);
            temp.push_back(height);
        } else {
            temp.push_back(height);
            temp.push_back(width);
        }
    }
    quickSort(v, 0, v.size() - 1);

    long result = 1;
    int start, end;
    for (int i = n - 1; i >= 0; --i) {
        start = i;
        end = -1;
        for (--i; i >= 0; --i) {
            if (v[i][1] < v[start][1] && v[i][0] < v[start][0]) {
                end = i;
                break;
            }
        }
        ++i;

        result = result * (start - end) % 1000000007;
    }
    cout << result;
    return 0;
}