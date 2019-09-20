#include <iostream>
#include <vector>

using namespace std;

int main() {
//    int t;
//    cin >> t;
//    for (int i = 0; i < t; i++) {
//        int n;
//        cin >> n;
//        string s;
//        cin >> s;
//        if (n < 11)
//            cout << "NO" << endl;
//        else if (n == 11) {
//            if (s[0] == '8')
//                cout << "YES" << endl;
//            else
//                cout << "NO" << endl;
//        } else {
//            int idx = 0;
//            while (s[idx] != '8')
//                ++idx;
//            if (n - idx >= 11)
//                cout << "YES" << endl;
//            else
//                cout << "NO" << endl;
//        }
//    }

    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    for (int i = 0; i < k; ++i) {
        int min = 0;
        while (v[min] == 0) ++min;

        if (min == n - 1) {
            cout << "0" << endl;
            break;
        }

        for (int j = 0; j < n; ++j) {
            if (v[j] > 0 && v[j] < v[min])
                min = j;
        }

        int temp = v[min];
        cout << temp << endl;

        for (int j = 0; j < n; ++j) {
            if (v[j] - temp < 0)
                v[j] = 0;
            else
                v[j] = v[j] - temp;
        }
    }
    return 0;
}