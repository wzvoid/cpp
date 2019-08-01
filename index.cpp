#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

int main() {
    array<int, 5> a = {3, 4, 5, 7, 8};
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        cout << *it << ",";
    }

    return 0;
}