//
// Created by 王振 on 2019-08-16.
//

#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    shared_ptr<int> p1 = make_shared<int>(10);
    shared_ptr<int> p3 = p1;
    shared_ptr<int> p2 = make_shared<int>(20);
    cout << *p1 << " " << *p2 << endl;
    swap(p1, p2);
    cout << *p1 << " " << *p2 << endl;
    cout << p3.use_count();
}