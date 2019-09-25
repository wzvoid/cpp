//
// Created by wzvoid on 2018/8/30.
//


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

bool duplicate(int numbers[], int length, int *duplication) {
    if (length <= 0)
        return false;
    unordered_map<int, int> um;
    for (int i = 0; i < length; ++i) {
        if (um.find(numbers[i]) != um.end()) {
            um[numbers[i]] += 1;
            *duplication = numbers[i];
            return true;
        } else {
            um[numbers[i]] = 1;
        }
    }
    return false;
}

int main() {
    unordered_map<string, int> mymap = {
            {"Mars",    3000},
            {"Saturn",  6000},
            {"Jupiter", 7000},
            {"Earth",   5000}};

    mymap.at("Mars") = 3396;
    mymap["Mars"] = 4000;
    for (auto &x: mymap) {
        std::cout << x.first << ": " << x.second << std::endl;
    }
    for (auto &x: mymap) {
        std::cout << "Element [" << x.first << ":" << x.second << "]";
        std::cout << " is in bucket #" << mymap.bucket(x.first) << std::endl;
    }
//    unsigned nbuckets = mymap.bucket_count();
//    std::cout << "mymap has " << nbuckets << " buckets:\n";
//    for (unsigned i = 0; i < nbuckets; ++i) {
//        std::cout << "bucket #" << i << " has " << mymap.bucket_size(i) << " elements.\n";
//    }
//    cout << mymap.max_load_factor();

    unordered_map<char, int> count;
    unordered_map<char, int>::iterator it;
    string s = "we are family";
    for (char &c:s) {
        if (count.find(c) != count.end()) {
            ++count[c];
        } else {
            count[c] = 1;
        }
    }
    for (auto &tmp:count) {
        cout << tmp.first << " " << tmp.second << endl;
    }

    count.insert(make_pair<char, int>('U', 2));
    count.insert({'W', 4});
    cout << (typeid(it) == typeid(count));

    int a[] = {5, 4, 3, 2, 7, 6, 5, 5};
    int b[10];
    duplicate(a, 8, b);
    cout << b[0];


    return 0;
}