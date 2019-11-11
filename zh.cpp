#include<iostream>
#include <vector>
#include <string>
#include "my_stl/wz_string.h"

using namespace std;

int main() {
    vector<int> v;
    cout << v.size() << "," << v.capacity() << endl;
    v.reserve(10);
    cout << v.size() << "," << v.capacity() << endl;
    v.resize(20);
    cout << v.size() << "," << v.capacity() << endl;
    return 0;
}