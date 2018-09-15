//
// Created by 王振 on 2018/9/15.
//

#include <iostream>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> vn;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vn.push_back(temp);
    }
    for (int j = 0; j < m; ++j) {
        char op;
        int id;
        cin >> op >> id;
        if (op == 'A') {
            vn[id - 1] += 1;
        } else if (op == 'B') {
            vn[id - 1] -= 1;
        }
    }
    int rank = vn[p - 1];
    int index = 1;
    for (int i = 0; i < n; i++) {
        if (i != p - 1 && vn[i] > rank) {
            index += 1;
        }
    }
    cout << index;
    return 0;
}