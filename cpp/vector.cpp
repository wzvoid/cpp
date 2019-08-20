//
// Created by wzvoid on 2018/8/31.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

namespace wz {
    void show() {
        cout << "wz";
    }
}

int main() {
//    std::vector<int> myvector{1, 2, 3, 4, 5, 6, 7, 8, 9};
//    std::vector<int>::iterator it;
//
////    it = myvector.begin();
////    it = myvector.insert(it, 200);
//    auto it2 = myvector.erase(myvector.begin() + 1);
//    for (auto &c:myvector)
//        cout << c << ",";
//    cout << endl << *(it2);

//    string *s = new string("wearehappy");
//    s->resize(3);
//    cout << *s;
    vector<int> v{15, 1, 3, 5, 7, 4, 2, 4, 8, 29};
    int left = v[0], right = 0;
    for (vector<int>::size_type i = 2; i < v.size(); ++i) {
        right += v[i];
    }
    cout << left << "," << right << endl;
    vector<int>::size_type j = 1;
    for (; j < v.size() - 1; ++j) {
        if (left == right) break;
        left += v[j];
        right -= v[j + 1];
        cout << left << "," << right << endl;
    }
    if (right == 0)
        cout << "none";
    else
        cout << v[j];
    return 0;
}