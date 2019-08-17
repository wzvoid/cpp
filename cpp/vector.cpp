//
// Created by wzvoid on 2018/8/31.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    std::vector<int> myvector{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int>::iterator it;

//    it = myvector.begin();
//    it = myvector.insert(it, 200);
    auto it2 = myvector.erase(myvector.begin() + 1);
    for (auto &c:myvector)
        cout << c << ",";
    cout << endl << *(it2);
    return 0;
}