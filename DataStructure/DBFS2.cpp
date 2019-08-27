//
// Created by 王振 on 2019/8/27.
//

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, vector<string>> um;
    um["you"] = {"alice", "bob", "claire"};
    um["bob"] = {"anuj", "peggy"};
    um["alice"] = {"peggy"};
    um["claire"] = {"thom", "jonny"};
    um["anuj"] = {};
    um["peggy"] = {};
    um["thom"] = {};
    um["jonny"] = {};

    unordered_map<string, bool> visited;
    visited["you"] = false;
    visited["bob"] = false;
    visited["alice"] = false;
    visited["claire"] = false;
    visited["anuj"] = false;
    visited["peggy"] = false;
    visited["thom"] = false;
    visited["jonny"] = false;


    return 0;
}