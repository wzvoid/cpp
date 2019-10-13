//
// Created by 王振 on 2019-08-04.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <list>
#include <unordered_set>

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

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> record;
    for (int i = 0; i < nums1.size(); i++) {
        record.insert(nums1[i]);
    }
    unordered_set<int> resultSet;
    for (int i = 0; i < nums2.size(); i++) {
        if (record.find(nums2[i]) != record.end()) {
            resultSet.insert(nums2[i]);
        }
    }
    vector<int> resultVector;
    for (unordered_set<int>::iterator iter = resultSet.begin(); iter != resultSet.end(); iter++) {
        resultVector.push_back(*iter);
    }
    return resultVector;
}

int main() {
    string str = "ffddreettyfff";
//    sort(str.begin(), str.end());
//    string::iterator s = unique(str.begin(), str.end());
//    str.resize(s - str.begin() - 1);
//    cout << str << endl;
//    cout << remove_dumplicate(str);
//    vector<int> a{4, 9, 5}, b{9, 4, 9, 8, 4};
//    for (auto &c:intersection(a, b))
//        cout << c << ",";
    int *p = new int(10);
    cout << *p;
    delete p;
    p = nullptr;
    delete p;
    return 0;
}
