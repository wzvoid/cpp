//
// Created by 王振 on 2018/9/15.
//

// https://blog.csdn.net/y201619819/article/details/81162790

#include<iostream>

using namespace std;

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t = 0;
        int j = i;
        while (j % 5 == 0) {
            t++;
            j /= 5;
        }
        ans += t * (n - i + 1);
    }
    cout << ans << endl;
}

