#include <iostream>
#include <cstdlib>
#include <cstring>

#define TEMP 100

using namespace std;

class wz_string final {
public:
    /*友元声明开始*/
    friend istream &operator>>(istream &, wz_string &);

    friend ostream &operator<<(ostream &, const wz_string &);
    /*友元声明结束*/

    /*构造函数开始*/
    wz_string();

    wz_string(const wz_string &);

    wz_string(const char *); // 为了使用隐式类型转换，不要使用关键字 explicit
    /*构造函数结束*/

    ~wz_string();

    /*成员函数开始*/
    size_t length();

    bool empty();

    const char *c_str();

    /*成员函数结束*/

    wz_string &operator=(const wz_string &);

private:
    char *p_str;
    size_t p_length;
};

istream &operator>>(istream &, const wz_string &);

ostream &operator<<(ostream &, const wz_string &);

wz_string::wz_string() : p_str(nullptr), p_length(0) { cout << "default constructor" << endl; }

wz_string::wz_string(const char *str) : p_str(nullptr), p_length(0) { //可以用委托构造函数
    if (str == nullptr)
        return;
    p_length = strlen(str);
    p_str = new char[p_length + 1]; // 深拷贝
    strcpy(p_str, str);
    cout << "const char* constructor" << endl;
}

wz_string::wz_string(const wz_string &str) : p_str(nullptr), p_length(0) {
    if (str.p_str == nullptr)
        return;
    p_length = str.p_length;
    p_str = new char[p_length + 1]; // 深拷贝
    strcpy(p_str, str.p_str);
    cout << "copy constructor" << endl;
}

wz_string::~wz_string() {
    delete[] p_str;
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

    cout << "copy assignment operator" << endl;
    return *this;
}

istream &operator>>(istream &in, wz_string &str) {
    char c[TEMP];
    if (in >> c) {
        delete[] str.p_str;
        str.p_length = strlen(c);
        str.p_str = new char[str.p_length + 1];
        strcpy(str.p_str, c);
    }
}

ostream &operator<<(ostream &out, const wz_string &str) {
    if (str.p_str != nullptr)
        out << str.p_str;
    return out;
}

int main() {
//    wz_string w = "wzvoid";
////    cin >> w;
//    cout << w.length() << endl;
//    cout << w.empty() << endl;
//    cout << w << endl;
    return 0;
}
