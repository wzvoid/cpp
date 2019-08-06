#include<iostream>

using namespace std;

class A {
private:
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
public:
    A() : a(0), b(0) {}

    A(int a, int b) : a(a), b(b) {}

    virtual void fun() { cout << "A::fun() called "; }
};

class B : public A {
private:
    int b;
public:
    B() : b(0) {}

    explicit B(int b) : b(b) {}

    void fun() override { cout << "B::fun() called "; }
};

//class C : public B {
//public:
//    void fun() override { cout << "C::fun() called "; }
//};

int main() {
    A a;
//    B *b = new C();
    a.fun();
    cout << sizeof(a);
//    b->fun();
    return 0;
}