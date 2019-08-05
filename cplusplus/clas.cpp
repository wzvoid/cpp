//
// Created by 王振 on 2019-08-04.
//
#include <iostream>

using namespace std;

class Base {
public:
    Base() : a(5) { cout << "Base 构造" << endl; }

    explicit Base(int a) : a(a) { cout << "Base explicit 构造" << endl; }

    ~Base() { cout << "Base 析构" << endl; };

    static void show() { cout << "Base show" << endl; }

    int a;
};

//class Derived : public Base {
//public:
//    Derived() : Base(55), b(60) { cout << "Derived 构造" << endl; };
//
//    ~Derived() { cout << "Derived 析构" << endl; };
//
//    void show() override { cout << "Derived show" << endl; }
//
//    int b;
//};

int main() {
//    Derived d;
//    Base e;
//    cout << d.a << endl;
//    d.show();
    enum class WORKDAY {
        MON, TUE = 9, WED, THU, FRI, SAT, SUN
    };
    Base b(50);
    string s = "ssss";
    return 0;
}
