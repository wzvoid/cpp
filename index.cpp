#include <iostream>
#include <vector>

using namespace std;

int main() {
    int d;
    cin >> d;
    vector<vector<int>> v;
    for (int i = 0; i < 4; i++) {
        vector<int> t;
        for (int j = 0; j < 4; j++) {
            int val;
            cin >> val;
            t.push_back(val);
        }
        v.push_back(t);
    }

    cout << endl;
    for (auto &c:v) {
        for (auto b:c)
            cout << b << " ";
        cout << endl;
    }
    cout << endl;

    if (d == 2) {
        for (int i = 0; i <= 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if ((v[j][i] == v[j + 1][i]) || (v[j + 1][i] == 0)) {
                    v[j + 1][i] += v[j][i];
                    v[j][i] = 0;
                }
            }
        }
    } else if (d == 1) {
        for (int i = 0; i <= 3; ++i) {
            for (int j = 2; j >= 0; --j) {
                if (v[j][i] == v[j + 1][i]) {
                    v[j][i] += v[j + 1][i];
                    v[j + 1][i] = 0;
                }

            }
        }
    } else if (d == 4) {
        for (int i = 0; i <= 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if ((v[i][j] == v[i][j + 1]) || (v[i][j + 1] == 0)) {
                    v[i][j + 1] += v[i][j];
                    v[i][j] = 0;
                }
            }
        }
    } else if (d == 3) {
        for (int i = 0; i <= 3; ++i) {
            for (int j = 3; j > 0; --j) {
                if ((v[i][j] == v[i][j - 1]) || (v[i][j - 1] == 0)) {
                    v[i][j - 1] += v[i][j];
                    v[i][j] = 0;
                }
            }
        }
    }

    for (auto &c:v) {
        for (auto b:c)
            cout << b << " ";
        cout << endl;
    }

    return 0;
}