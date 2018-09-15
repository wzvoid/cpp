//
// Created by 王振 on 2018/9/15.
//

#include <iostream>
#include <deque>
#include <list>
#include <vector>

using namespace std;

int main() {
    deque<int> dig;
    deque<char> op;
    string s;
    cin >> s;
    for (auto c:s) {
        if (c >= '0' && c <= '9')
            dig.push_back(c - '0');
        else
            op.push_back(c);
    }

    auto it1 = dig.begin();
    auto it2 = op.begin();
    while (it2 != op.end()) {
        if ((*it2) == '*' || (*it2) == '/') {
            char op_temp = *it2;
            it2 = op.erase(it2);
            int a, b;
            a = *it1;
            ++it1;
            b = *it1;
            --it1;
            it1 = dig.erase(it1);
            it1 = dig.erase(it1);
            if (op_temp == '*')
                it1 = dig.insert(it1, a * b);
            else if (op_temp == '/')
                it1 = dig.insert(it1, a / b);
        } else {
            ++it1;
            ++it2;
        }
        for (auto c:dig)
            cout << c << " ";
        cout << endl;
        for (auto d:op)
            cout << d << " ";
        cout << endl;
        cout << "**********" << endl;
    }

    while (!op.empty()) {
        char op_temp = op.front();
        op.pop_front();
        int a, b;
        a = dig.front();
        dig.pop_front();
        b = dig.front();
        dig.pop_front();
        if (op_temp == '+') {
            dig.push_front(a + b);
        } else if (op_temp == '-')
            dig.push_front(a - b);
    }

    cout << dig.front();
    return 0;
}