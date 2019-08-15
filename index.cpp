#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <ext/hash_map>

using namespace std;

template<typename T>
T compare(T x, T y) {
    return x > y ? x : y;
}


int main() {
//    string s1 = "wzvoid";
//    const char *s2 = "wzvoid";
//    string *s3 = new string("wzvoid");
//    char *s4 = (char *) malloc(sizeof(char) * 6);
//    cout << sizeof(s1) << endl;
//    cout << sizeof(s2) << endl;
//    cout << sizeof(s3) << endl;
//    cout << sizeof(s4) << endl;
    cout << compare(4, 6);
    return 0;
}