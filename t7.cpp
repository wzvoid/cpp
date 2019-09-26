//
// Created by Administrator on 2019/9/26.
//

#include<iostream>

using namespace std;

class Base {
public:
    int _base = 1;

    void fun() {
        cout << "Base()" << endl;
    }
};

class A : virtual public Base {
public:
    int _base = 2;
};

class C : virtual public Base {
public:
    int _base = 3;
};

class D : public A, public C {

};

int main() {
    D d;
    d.fun();//Base()
    d.A::fun();//Base()
    d.C::fun();//Base()
    cout << d.Base::_base << endl;//1
    cout << d.A::_base << endl;//2
    cout << d.C::_base << endl;//3
    return 0;
}
