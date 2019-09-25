#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <utility>

using namespace std;

int main() {
    map<string, int> mymap = {
            {"Mars",    3000},
            {"Saturn",  4000},
            {"Jupiter", 5000},
            {"Earth",   6000}};

    mymap.at("Mars") = 3396;
    mymap["Mars"] = 4000;
    mymap["Mars"] = 4001;
    mymap.insert(pair<string, int>("Mars", 4001));
    mymap.insert(make_pair("Mars", 4003));
    mymap.insert(make_pair<string, int>("Mars", 4003));
    for (auto &x: mymap) {
        std::cout << x.first << ": " << x.second << std::endl;
    }
    if (mymap.erase("Saturn"))
        cout << "Saturn!" << endl;
    else
        cout << "Not Found!" << endl;
    for (auto &x: mymap) {
        std::cout << x.first << ": " << x.second << std::endl;
    }
//    for (auto &x: mymap) {
//        std::cout << "Element [" << x.first << ":" << x.second << "]";
//        std::cout << " is in bucket #" << mymap.bucket(x.first) << std::endl;
//    }

//    unsigned nbuckets = mymap.bucket_count();
//    std::cout << "mymap has " << nbuckets << " buckets:\n";
//    for (unsigned i = 0; i < nbuckets; ++i) {
//        std::cout << "bucket #" << i << " has " << mymap.bucket_size(i) << " elements.\n";
//    }
//    cout << mymap.max_load_factor();

//    unordered_map<char, int> count;
//    unordered_map<char, int>::iterator it;
//    string s = "we are family";
//    for (char &c:s) {
//        if (count.find(c) != count.end()) {
//            ++count[c];
//        } else {
//            count[c] = 1;
//        }
//    }
//    for (auto &tmp:count) {
//        cout << tmp.first << ": " << tmp.second << endl;
//    }
//
//    count.insert(make_pair<char, int>('U', 2));
//    count.insert({'W', 4});
//    cout << (typeid(it) == typeid(count));
    return 0;
}