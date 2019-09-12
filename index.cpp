#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

bool isNum(string &str) {
    for (int i = 0; i < str.size(); ++i) {
        char tmp = (char) str[i];
        if (tmp < '0' || tmp > '9') {
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> v;
    string s;
    while (cin >> s) {
        v.push_back(s);
        if (s == "=")
            break;
    }
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (i % 2 == 0 && !isNum(v[i])) {
            cout << "ERROR line:" << i;
            return 0;
        }
        if (i % 2 == 1 && (v[i] != "+" && v[i] != "-" && v[i] != "=")) {
            cout << "ERROR line:" << i;
            return 0;
        }
        if (i % 2 == 0) {
            if (i == 0)
                sum += stoi(v[i]);
            else if (v[i - 1] == "+")
                sum += stoi(v[i]);
            else if (v[i - 1] == "-")
                sum -= stoi(v[i]);
        } else if (i % 2 == 1 && v[i] == "=")
            cout << sum;

    }
    return 0;
}