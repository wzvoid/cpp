#include<iostream>
#include <cstddef>
#include <array>
#include <string>

using namespace std;

class A {
public:
    int a = 0;
    int c = 0;

    A() : a(0), c(0) { show(); }

    A(int a, int c) : a(a), c(c) {}

    virtual void fun() { cout << "A::fun() called "; }

    void show() {
        cout << "class A";
    }
};

class B : public A {
public:
    int b;

    B() : b(0) {}

    explicit B(int b) : b(b) {}

    void fun() override { cout << "B::fun() called "; }

    void show() {
        cout << "class B:" << b;
    };
};

int main() {
    string s = "1.2344322";
    return 0;
}