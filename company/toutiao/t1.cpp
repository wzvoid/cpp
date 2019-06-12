//
// Created by 王振 on 2018/9/17.
//

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> v;
    int temp, n;
    cin >> n;
    if (n < 3) {
        cout << -1;
    } else {
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            v.push_back(temp);
        }

        bool flag = false;
        long f = 0;

        for (auto i = v.begin() + 2; i != v.end(); ++i) {
            int sum = 0;
            sort(v.begin(), i + 1);
            for (auto j = v.begin(); j < i; ++j)
                sum += *j;
            if (sum > *i) {
                flag = true;
                f = i - v.begin() + 1;
                break;
            }
        }

        if (flag)
            cout << f;
        else
            cout << -1;
    }
    return 0;
}