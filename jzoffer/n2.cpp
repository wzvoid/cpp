//
// Created by 王振 on 2019-07-28.
//
//替换空格
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 0-14
// 0-20
// 3个
// we are happy a'\0'
// we%20are%20happy%20q'\0'
void replaceSpace(char *str, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ')
            count++;
    }
    for (int i = length; i >= 0; i--) {
        if (str[i] != ' ') {
            str[i + 2 * count] = str[i];
        } else {
            count--;
            str[i + 2 * count] = '%';
            str[i + 2 * count + 1] = '2';
            str[i + 2 * count + 2] = '0';
        }
    }

//    int count = 0; //空格个数
//    for (int i = length; i >= 0; --i) {
//        if (str[i] == ' ') {
//            for (int j = length + 2 * count; j > i; --j) //注意长度是不断变化的，即，每多一个空格，长度增长2
//                str[j + 2] = str[j];
//            str[i] = '%';
//            str[i + 1] = '2';
//            str[i + 2] = '0';
//            ++count;
//        }
//    }
}

int main() {
    char str[100] = "we  are happy  ";
    replaceSpace(str, 16);
    string s(str);
    cout << s;
    return 0;
}