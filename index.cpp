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

bool myfunc(int i, int j) { return i > j; }

int main() {
    vector<int> v = {4, 3, 2, 7, 8, 2, 3, 1};
    stable_sort(v.begin(), v.end(), myfunc);
    for (auto c:v)
        cout << c;
    return 0;
}