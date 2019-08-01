//
// Created by 王振 on 2019-07-31.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//AABCD
//CDAA
//AABCD
//ABCD
//AABCD
//CFS

string reverse_str(string s, int k) {
    reverse(s.begin(), s.begin() + (k % s.length()));
    reverse(s.begin() + (k % s.length()), s.end());
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    vector<string> v;
    for (int i = 0; i < 6; ++i) {
        string temp;
        getline(cin, temp);
        v.push_back(temp);
    }
    for (int j = 0; j < 6; j = j + 2) {
        string origin = v[j], target = v[j + 1];
        int result = 0;
        for (size_t i = 0; i < origin.length(); ++i) {
            if (reverse_str(origin, i).find(target) != string::npos) {
                result = 1;
                break;
            }
        }
        cout << result;
    }
    return 0;
}
