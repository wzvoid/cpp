//
// Created by 王振 on 2019/9/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template<typename T>
void show(T &a, T &b);

int main() {
    double a = 5.2, b = 6.1;
    show<double>(a, b);
    return 0;
}

template<typename T>
void show(T &a, T &b) {
    cout << a << ", " << b;
}