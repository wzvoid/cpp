#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <list>
#include <map>
#include <ext/hash_map>

using namespace std;

int main() {
    string s1 = "wzvoid";
    const char *s2 = "wzvoid";
    string *s3 = new string("wzvoid");
    char *s4 = (char *) malloc(sizeof(char) * 6);
    cout << sizeof(s1) << endl;
    cout << sizeof(s2) << endl;
    cout << sizeof(s3) << endl;
    cout << sizeof(s4) << endl;
//    map<string, int> m;
//    m["w"] = 21;
//    m["c"] = 20;
//    m["a"] = 19;
//    if (m.find("b") == m.end())
//        cout << "no b";
//    else cout << m["a"];
    return 0;
}