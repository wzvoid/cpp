#include <iostream>
#include <string>
//#include <vector>
//#include <deque>
//#include <algorithm>
//#include <set>
//#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
typedef pair<int, int> pp;

int main() {
    int n;
    cin >> n;
    pp *p = new pp[n];
//    int *c = new int[n];
//    cout << c[0];
    unordered_map<string, int> q;
    q.insert(make_pair("3", 55555));
    cout << q["3"];
//    for (int i = 0; i < n; ++i) {
//        cin >> p[i].first;
//        p[i].second = p[i].first + 1;
//    }
//    cout << p[0].first << ", " << p[0].second;
    return 0;
}