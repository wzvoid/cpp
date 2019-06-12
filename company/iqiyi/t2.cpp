//
// Created by 王振 on 2018/9/15.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;
    if (str.length() == 6) {
        int result = 0;
        for (int i = 0; i < 3; i++) {
            result += str[i] - str[i + 3];
        }
        if (result == 0) {
            cout << 0;
        } else if (result < 0) {
            int res1 = 0;
            result = -result;
            int t = result;
            for (int i = 0; i < 3; i++) {
                if ((str[i] - '0') + result > 9) {
                    result -= 9 - (str[i] - '0');
                    res1++;
                } else {
                    res1++;
                    break;
                }
            }
            int res2 = 0;
            for (int i = 3; i < 6; i++) {
                if ((str[i] - '0') - t < 0) {
                    t -= str[i] - '0';
                    res2++;
                } else {
                    res2++;
                    break;
                }
            }
            cout << min(res1, res2);
        } else {
            int res1 = 0;
            int t = result;
            for (int i = 3; i < 6; i++) {
                if ((str[i] - '0') + result > 9) {
                    result -= 9 - (str[i] - '0');
                    res1++;
                } else {
                    res1++;
                    break;
                }
            }
            int res2 = 0;
            for (int i = 0; i < 3; i++) {
                if ((str[i] - '0') - t < 0) {
                    t -= str[i] - '0';
                    res2++;
                } else {
                    res2++;
                    break;
                }
            }
            cout << min(res1, res2);
        }
    }
}

