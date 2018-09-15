//
// Created by wzvoid on 2018/8/30.
//


#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool duplicate(int numbers[], int length, int *duplication) {
    if (length <= 0)
        return false;
    unordered_map<int, int> um;
    for (int i = 0; i < length; ++i) {
        if (um.find(numbers[i]) != um.end()) {
            um[numbers[i]] += 1;
            *duplication = numbers[i];
            return true;
        } else {
            um[numbers[i]] = 1;
        }
    }
    return false;
}

int main() {
//    unordered_map<string, int> mp = {
//            {"Mars",    3000},
//            {"Saturn",  60000},
//            {"Jupiter", 70000}};
//
//    mp.at("Mars") = 3396;
//    mp.at("Saturn") += 272;
//    mp.at("Jupiter") = mp.at("Saturn") + 9638;
//
//    for (auto &x: mp) {
//        std::cout << x.first << ": " << x.second << std::endl;
//    }
//
//
//    unordered_map<char, int> count;
//    unordered_map<char, int>::iterator it;
//    string s = "we are family";
//
//    for (char c:s) {
//        if (count.find(c) != count.end()) {
//            ++count[c];
//        } else {
//            count[c] = 1;
//        }
//    }
//
//    for (auto tmp:count) {
//        cout << tmp.first << " " << tmp.second << endl;
//    }
//
//    count.insert(make_pair<char, int>('U', 2));
//    count.insert({'W', 4});
//    cout << (typeid(it) == typeid(count));

    int a[] = {5, 4, 3, 2, 7, 6, 5, 5};
    int b[10];
    duplicate(a, 8, b);
    cout << b[0];
    return 0;
}