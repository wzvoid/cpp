//
// Created by 王振 on 2019-08-12.
//

#ifndef CPP_WZ_STRING_H
#define CPP_WZ_STRING_H

#include <iostream>

class wz_string {
public:
    friend std::istream &operator>>(std::istream &, wz_string &);

    friend std::ostream &operator<<(std::ostream &, const wz_string &);

    wz_string();

    wz_string(const wz_string &);

    wz_string(const char *); // 为了使用隐式类型转换，不要使用关键字 explicit

    ~wz_string();

    size_t length();

    bool empty();

    const char *c_str();

    wz_string &operator=(const wz_string &);

    wz_string &operator+(const wz_string &);

private:
    char *p_str;
    size_t p_length;
};

std::istream &operator>>(std::istream &, const wz_string &);

std::ostream &operator<<(std::ostream &, const wz_string &);

#endif //CPP_WZ_STRING_H
