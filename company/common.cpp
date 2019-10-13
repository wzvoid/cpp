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

string remove_dumplicate(string &s) {
    if (s.length() <= 1)
        return s;
    string str;
    for (string::size_type i = 0; i < s.length(); ++i) {
        if (s.at(i) != ' ') {
            str.push_back(s.at(i));
            for (string::size_type j = i + 1; j < s.length(); ++j) {
                if (s.at(i) == s.at(j))
                    s.at(j) = ' ';
            }
        }
    }
    return str;
}

void replaceSpace(char *str, int length) {
    if (!str)
        return;
    int count = 0;
    for (int i = length; i >= 0; --i) {
        if (str[i] == ' ') {
            ++count;
            for (int j = length + 2 * count; j >= i + 2; --j) {
                str[j] = str[j - 2];
            }
            str[i] = '%';
            str[i + 1] = '2';
            str[i + 2] = '0';
        }
    }
}

int main() {
    string str = "ffddreettyfff";
//    sort(str.begin(), str.end());
//    string::iterator s = unique(str.begin(), str.end());
//    str.resize(s - str.begin() - 1);
//    cout << str << endl;
    cout << remove_dumplicate(str);
    return 0;
}
