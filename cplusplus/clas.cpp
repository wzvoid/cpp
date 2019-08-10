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

    virtual void show() {
        cout << "class A";
    }
};

class B : public A {
public:
    int b;

    B() : b(0) {}

    explicit B(int b) : b(b) {}

    void fun() override { cout << "B::fun() called "; }

    void show() override {
        cout << "class B:" << b;
    };
};

int main() {
    char *p1 = "abcdef";

    char *p2 = "abcdef";

    char a[] = "abcdef";
//    cout << (unsigned long) a << endl << (unsigned long) p1 << endl << (unsigned long) p2;
    printf("%0x,%0x,%0x", (unsigned long) a, (unsigned long) p1, (unsigned long) p2);
    return 0;
}