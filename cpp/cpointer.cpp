//
// Created by 王振 on 2019-07-31.
//

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <cassert>
#include <unordered_map>

using namespace std;
typedef pair<int, int> pp;

void f(int i) {
    cout << "int value";
}

void f(int *i) {
    cout << "pointer value";
}

int main(int argc, char *argv[]) {
//    int n = 5;
//    int **p = (int **) malloc(sizeof(int *) * n);
//    for (int i = 0; i < n; ++i) {
//        int *q = (int *) malloc(sizeof(int) * n);
//        p[i] = q;
//        for (int j = 0; j < n; ++j) {
//            *(*(p + i) + j) = i + j + 1;
//        }
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            printf("%d ", p[i][j]);
//        }
//        printf("\n");
//    }
//    for (int i = 0; i < n; i++) {
//        free(p[i]);
//    }
//    free(p);
    f(nullptr);
    NULL
    return 0;
}