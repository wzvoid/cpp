//
// Created by 王振 on 2019/9/27.
//

#include <iostream>
#include <vector>

#define M 1000

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> v(1, 0);
    vector<int> w(1, 0);
    for (int i = 0; i < t; ++i) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < t; ++i) {
        int temp;
        cin >> temp;
        w.push_back(temp);
    }
    int bagV;
    cin >> bagV;

//    int w[5] = {0, 2, 3, 4, 5};            //商品的体积2、3、4、5
//    int v[5] = {0, 3, 4, 5, 6};            //商品的价值3、4、5、6
//    int bagV = 8;                            //背包大小
    int dp[M][M] = {{0}};                    //动态规划表

    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= bagV; j++) {
            if (j < w[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }

    //动态规划表的输出
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 9; j++) {
//            cout << dp[i][j] << ' ';
//        }
//        cout << endl;
//    }
    cout << dp[t][bagV];

    return 0;
}