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

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return gcd(b, a % b);
}

int MinMultiple(int a, int b) {
    return (a * b) / gcd(a, b);
}

int GB(int a, int b) {
    if (a == b)
        return a;
    if (a < b) {
        int re = 1;
        for (int i = a; i <= b; ++i) {
            re = MinMultiple(re, i);
        }
        return re;
    }
}

int main() {
    int n, m;
    cin >> n;
    m = n + 1;
    int re1, re2;
    re1 = GB(n + 1, m);
    re2 = GB(1, m);
    while (re1 != re2) {
        ++m;
        re1 = MinMultiple(re1, m);
        re2 = MinMultiple(re2, m);
    }
    cout << m;
    return 0;
}