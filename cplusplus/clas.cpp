#include<iostream>
#include <cstddef>

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
    A a;
    B b;
//    a.fun();
    return 0;
}