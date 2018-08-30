//
// Created by wzvoid on 2018/8/30.
//


#include <iostream>
#include <unordered_map>
#include <string>
#include <map>

using namespace std;

int main() {
    unordered_map<string, int> mp = {
            {"Mars",    3000},
            {"Saturn",  60000},
            {"Jupiter", 70000}};

    mp.at("Mars") = 3396;
    mp.at("Saturn") += 272;
    mp.at("Jupiter") = mp.at("Saturn") + 9638;

    for (auto &x: mp) {
        std::cout << x.first << ": " << x.second << std::endl;
    }


    unordered_map<char, int> count;
    unordered_map<char, int>::iterator it;
    string s = "we are family";

    for (char c:s) {
        if (count.find(c) != count.end()) {
            ++count[c];
        } else {
            count[c] = 1;
        }
    }

    for (auto tmp:count) {
        cout << tmp.first << " " << tmp.second << endl;
    }

    count.insert(make_pair<char, int>('U', 2));
    count.insert({'W', 4});
    cout << (typeid(it) == typeid(count));
    return 0;
}