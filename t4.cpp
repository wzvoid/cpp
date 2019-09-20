#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < k; ++i) {
        cout << "-------------" << endl;
        for (auto c:v)
            cout << c << " ";
        cout << endl << "-------------" << endl;

        if (v[n - 1] == 0) {
            cout << "0" << endl;
            continue;
        } else {
            int min = 0;
            while (v[min] == 0)
                ++min;
            int temp = v[min];
            cout << "min: " << temp << endl;
            for (int j = 0; j < n; ++j) {
                if (v[j] > 0) {
                    if (v[j] - temp < 0)
                        v[j] = 0;
                    else
                        v[j] = v[j] - temp;
                }
            }
        }
    }

    return 0;
}