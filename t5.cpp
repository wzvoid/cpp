#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<long> s(n * n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i] = t;
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        b[i] = t;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s[i * n + j] = a[i] + b[j];
        }
    }
    long result = s[0];
    for (int i = 1; i < n * n; i++) {
        result ^= s[i];
    }
    cout << result;
    return 0;
}