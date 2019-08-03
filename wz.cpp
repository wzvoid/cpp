#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <cassert>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) {
//    vector<int> v = {0};
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; ++i) {
//        int grade;
//        cin >> grade;
//        v.push_back(grade);
//    }
//    int q;
//    cin >> q;
//    vector<int> b;
//    for (int j = 0; j < q; ++j) {
//        int rate;
//        cin >> rate;
//        b.push_back(rate);
//    }

    vector<vector<int>> v;
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> arr;
        for (int j = 0; j < n; ++j) {
            int b;
            cin >> b;
            arr.push_back(b);
        }
        v.push_back(arr);
    }
    return 0;
}