//
// Created by 王振 on 2019-07-28.
//
#include <iostream>
#include <vector>

using namespace std;

bool find2array(int target, vector<vector<int>> array) {
    int row = array.size(), col = array[0].size();
    int i = row - 1, j = 0;
    while (i >= 0 && j < col) {
        if (array[i][j] == target)
            return true;
        else if (array[i][j] > target) {
            --i;
        } else {
            ++j;
        }
    }
    return false;
}

int main() {

    return 0;
}