#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <set>

using namespace std;

int main() {
    vector<int> v{5, 3, 8, 1, 7, 0, 0};
    for (vector<int>::size_type i = 0; i < v.size() - 1; ++i) {
        for (vector<int>::size_type j = 0; j < v.size() - 1 - i; ++j) {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
    for (auto &c:v)
        cout << c << " ";
    return 0;
}