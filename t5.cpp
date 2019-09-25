#include<iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cin >> m;
    vector<pair<int, int>> q;
    for (int j = 0; j < m; ++j) {
        int l, r;
        cin >> l >> r;
        q.emplace_back(make_pair(l, r));
    }
    for (int k = 0; k < m; ++k) {
        int l = q[k].first, r = q[k].second;
        unordered_map<int, int> s;
        int res = 0;
        for (int i = l - 1; i <= r - 1; ++i) {
            if (s.find(v[i]) == s.end()) {
                s[v[i]] = 1;
            } else {
                s[v[i]] += 1;
            }
        }
        for (auto it = s.begin(); it != s.end(); ++it) {
            if (it->second == 1)
                ++res;
        }
        cout << res << endl;
    }
    return 0;
}