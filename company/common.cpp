//
// Created by 王振 on 2019-08-04.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <list>

using namespace std;

string remove_dumplicate(string s) {
    if (s.length() < 2)
        return s;
    string str;
    for (string::size_type i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            str.push_back(s[i]);
            for (string::size_type j = i + 1; j < s.length(); ++j) {
                if (s.at(i) == s.at(j))
                    s[j] = ' ';
            }
        }
    }
    return str;
}

int main() {
    string str = "fdreettyhgh";
//    sort(str.begin(), str.end());
    string::iterator s = unique(str.begin(), str.end());
    str.resize(s - str.begin() - 1);
    cout << str << endl;
    cout << remove_dumplicate("fdreettyhgh");
    return 0;
}
