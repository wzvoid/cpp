//
// Created by 王振 on 2019-08-09.
//

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>

using namespace std;

class wz_string final {
public:
    wz_string();

    wz_string(const wz_string &);

    wz_string(const char *);

    ~wz_string();

    size_t length();

    bool empty();

    friend istream &operator>>(istream &, const wz_string &);

    friend ostream &operator<<(ostream &, const wz_string &);


private:
    char *p_str;
    size_t p_length;
};

istream &operator>>(istream &, const wz_string &);

ostream &operator<<(ostream &, const wz_string &);

wz_string::wz_string() : p_str(nullptr), p_length(0) {}

wz_string::wz_string(const char *str) : wz_string() {
    if (str == nullptr)
        return;
    p_length = strlen(str);
    p_str = new char[p_length + 1];
    strcpy(p_str, str);
}

wz_string::wz_string(const wz_string &str) : p_str(nullptr), p_length(0) {
    if (str.p_str == nullptr)
        return;
    p_length = str.p_length;
    p_str = new char[p_length + 1];
    strcpy(p_str, str.p_str);
}

wz_string::~wz_string() {
    delete[] p_str;
    p_str = nullptr;
}

size_t wz_string::length() {
    return p_length;
}

bool wz_string::empty() {
    return p_length > 0;
}

istream &operator>>(istream &in, const wz_string &str) {

}

ostream &operator<<(ostream &out, const wz_string &str) {

}

int main() {
    wz_string w("wzvoid");
    cout << w.length();
    return 0;
}
