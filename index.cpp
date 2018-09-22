#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

struct Obj {
    int val;
    explicit Obj(int n):val(n){}
};

bool myfunc(int i, int j) {
    return i < j;
}

bool is_sorted(vector<int> &v){
    int first = 0, end = v.size() - 1;
    if(first == end)
        return true;
    int next = first;
    while (next != end){
        ++next;
        if(v[next] < v[first])
            return false;
        ++first;
        cout << next << " " << first << endl;
    }
    return true;
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    stable_sort(v.begin(), v.end(), myfunc);
    for (auto c:v)
        cout << c;
    cout << endl;
    cout << is_sorted(v);
    return 0;
}