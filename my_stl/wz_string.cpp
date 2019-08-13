//
// Created by 王振 on 2019-08-12.
//

#include "wz_string.h"
#include <cstring>

#define TEMP 100

wz_string::wz_string() : p_str(nullptr), p_length(0) {
    std::cout << "default constructor" << std::endl;
}

wz_string::wz_string(const wz_string &str) : p_str(nullptr), p_length(0) {
    if (str.p_str == nullptr)
        return;
    p_length = str.p_length;
    p_str = new char[p_length + 1]; // 深拷贝
    strcpy(p_str, str.p_str);
    std::cout << "copy constructor" << std::endl;
}

wz_string::wz_string(const char *str) : p_str(nullptr), p_length(0) { //可以用委托构造函数
    if (str == nullptr)
        return;
    p_length = strlen(str);
    p_str = new char[p_length + 1]; // 深拷贝
    strcpy(p_str, str);
    std::cout << "const char* constructor" << std::endl;
}

wz_string::~wz_string() {
    delete[] p_str;
//    this->p_str = nullptr; // 空悬指针,这里没必要置空
}

size_t wz_string::length() {
    return p_length;
}

bool wz_string::empty() {
    return p_length > 0;
}

const char *wz_string::c_str() {
    return p_str;
}

wz_string &wz_string::operator=(const wz_string &str) {
    delete[] this->p_str; // 可以delete nullptr
    this->p_length = strlen(str.p_str);
    this->p_str = new char[this->p_length + 1];
    strcpy(this->p_str, str.p_str);
    std::cout << "copy assignment operator=" << std::endl;
    return *this;
}

//wz_string &wz_string::operator+(const wz_string &str) {
//    char *temp = this->p_str;
//    this->p_length += str.p_length;
//    this->p_str = new char[this->p_length + str.p_length + 1];
//    if (temp)
//        strcat(this->p_str, temp);
//    strcat(this->p_str, str.p_str); //参数不能为NULL
//    delete[] temp;
//    std::cout << "operator+ overload" << std::endl;
//    return *this;
//}

wz_string operator+(const wz_string &lv, const wz_string &rv) {
    wz_string ws;
    ws.p_length = lv.p_length + rv.p_length;
    ws.p_str = new char[ws.p_length + 1]();
    if (lv.p_str)
        strcat(ws.p_str, lv.p_str);
    if (rv.p_str)
        strcat(ws.p_str, rv.p_str);
    std::cout << "operator+ overload" << std::endl;
    return ws;
}

std::istream &operator>>(std::istream &in, wz_string &str) {
    char c[TEMP];
    if (in >> c) {
        delete[] str.p_str;
        str.p_length = strlen(c);
        str.p_str = new char[str.p_length + 1];
        strcpy(str.p_str, c);
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const wz_string &str) {
    if (str.p_str != nullptr)
        out << str.p_str;
    return out;
}