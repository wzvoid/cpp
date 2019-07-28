#include <iostream>
#include <string>
//#include <vector>
//#include <deque>
//#include <algorithm>
//#include <set>
//#include <unordered_set>
#include <map>
#include <cassert>
#include <forward_list>
#include <unordered_map>
#include <array>

using namespace std;
typedef pair<int, int> pp;

int main() {
    int *p1 = new int[10];
    int *p2 = new int;
    int *p3 = new int(8);
    for (int i = 1; i <= 10; ++i) {
        p1[i] = i;
    }
    cout << *p3;
    return 0;
}