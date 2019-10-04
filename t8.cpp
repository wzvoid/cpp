//
// Created by 王振 on 2019/9/27.
//

#include <iostream>

using namespace std;

int nums[255];

int f(int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else if (n == 3) {
        return 2;
    } else {
        int f1 = 1;
        int f2 = 2;
        for (int i = 4; i <= n; ++i) {
            int t = f2;
            f2 = (i - 1) * (f1 + f2);
            f1 = t;
        }
        return f2;
    }
}

int main() {
    int n;
    cin >> n;
    cout << n * f(n - 1);
    return 0;
}