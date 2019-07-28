#include <iostream>
#include <string>
//#include <vector>
//#include <deque>
//#include <algorithm>
//#include <set>
//#include <unordered_set>
#include <map>
#include <cassert>
#include <unordered_map>

using namespace std;
typedef pair<int, int> pp;

int main() {
    int n = 5;
    int **p = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i)
    {
        int *q = (int *)malloc(sizeof(int) * n);
        p[i] = q;
        for (int j = 0; j < n; ++j)
        {
            *(*(p + i) + j) = i + j + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        free(p[i]);
    }
    free(p);

    return 0;
}