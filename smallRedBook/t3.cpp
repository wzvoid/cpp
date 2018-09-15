//
// Created by 王振 on 2018/9/15.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int total, requests;
    cin >> total;
    cin >> requests;
    vector<int> v1, v2;
    for (int i = 0; i < requests; ++i) {
        int a, b;
        cin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
    }
    set<int> s1(v1.begin(), v1.end()), s2(v2.begin(), v2.end());
    if ((s1.size() + s2.size()) > requests)
        cout << 1;
    else
        cout << 0;
}