#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <list>
#include <map>
#include <unordered_set>
#include <set>
#include <unordered_set>

using namespace std;

//去除重复的字符
string remove_dumplicate(string &s) {
    if (s.length() <= 1)
        return s;
    string str;
    for (string::size_type i = 0; i < s.length(); ++i) {
        if (s.at(i) != ' ') {
            str.push_back(s.at(i));
            for (string::size_type j = i + 1; j < s.length(); ++j) {
                if (s.at(i) == s.at(j))
                    s.at(j) = ' ';
            }
        }
    }
    return str;
}

vector<int> interSection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> record;
    for (int i = 0; i < nums1.size(); i++) {
        record.insert(nums1[i]);
    }
    unordered_set<int> resultSet;
    for (int i = 0; i < nums2.size(); i++) {
        if (record.find(nums2[i]) != record.end()) {
            resultSet.insert(nums2[i]);
        }
    }
    vector<int> resultVector;
    for (unordered_set<int>::iterator iter = resultSet.begin(); iter != resultSet.end(); iter++) {
        resultVector.push_back(*iter);
    }
    return resultVector;
}

//买卖股票，一次买卖
// 7,1,5,4,6,3
vector<int> maxProfit1(vector<int> &prices) {
    vector<int> res(3, 0);
    if (prices.empty())
        return res;
    int profit = 0;
    int minPrice = prices[0];
    for (int i = 0; i < prices.size(); ++i) {
        if (prices[i] > minPrice) {
            if ((prices[i] - minPrice) > profit) {
                profit = prices[i] - minPrice;
                res[1] = i;
            }
        } else {
            minPrice = prices[i];
            res[0] = i;
        }
    }
    res[2] = profit;
//    for (int i = 1; i < v.size(); ++i) {
//        profit = max(profit, v[i] - minV);
//        minV = min(minV, v[i]);
//    }
    return res;
}

//买卖股票，不限制次数
int maxProfit2(vector<int> &prices) {
    if (prices.empty())
        return 0;
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1])
            profit += (prices[i] - prices[i - 1]);
    }
    return profit;
}

//股票问题，限制两次
// 7,1,5,4,6,3
int maxProfit3(vector<int> &prices) {
    if (prices.empty())
        return 0;
    int minPrice = prices[0];
    int maxPrice = prices[prices.size() - 1];
    int profit1 = 0;
    int profit2 = 0;
    int profit = 0;
    vector<int> a;
    for (int i = 0; i < prices.size(); ++i) {
        minPrice = min(minPrice, prices[i]);
        profit1 = max(profit1, prices[i] - minPrice);
        a.push_back(profit1);
    }
    for (int j = prices.size() - 1; j >= 0; --j) {
        maxPrice = max(maxPrice, prices[j]);
        profit2 = max(profit2, maxPrice - prices[j]);
        profit = max(profit, profit2 + a[j]);
    }
    return profit;
}

//最大子序列问题（dp）
int maxSubsequence(vector<int> &v) {
    if (v.empty())
        return 0;
    if (v.size() == 1)
        return v[0];
    vector<int> dp(v.size(), 0);
    dp[0] = v[0];
    for (int i = 1; i < v.size(); ++i) {
        dp[i] = max(v[i], dp[i - 1] + v[i]); //dp[i]表示以v[i]结尾的子序列之和
    }
    int k = dp[0];
    for (int j = 1; j < dp.size(); ++j) {
        if (dp[j] > k)
            k = dp[j];
    }
    return k;
}

//贪心算法，最大面值纸币问题 370元
int maxMoney(int money) {
    if (money <= 0)
        return 0;
    const int N = 7;
    int m[N] = {5, 2, 2, 3, 1, 3, 5};
    int v[N] = {1, 2, 5, 10, 20, 50, 100};
    int nums = 0;
    for (int i = N - 1; i >= 0; --i) {
        int c = min(money / v[i], m[i]);
//        int c = money / v[i]; // 如果不限定张数的话
        nums += c;
        money = money - v[i] * c;
    }
    if (money > 0)
        return -1;
    else
        return nums;
}

int main() {
    vector<int> v = {-2, 11, -4, 13, -5, -2};
    cout << maxMoney(520);
    return 0;
}
