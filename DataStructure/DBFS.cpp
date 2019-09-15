#include <iostream>
#include <stack>
#include <queue>

#define MaxVertexNum 100

using namespace std;

typedef struct {
    char vertex[MaxVertexNum];
    int edge[MaxVertexNum][MaxVertexNum];
    int vertex_nums, edge_nums;
} MGraph;

bool visited[MaxVertexNum];

void CreateGraph(MGraph &G) {
    G.vertex_nums = 7;
    G.edge_nums = 7;
    G.vertex[0] = 'a';
    G.vertex[1] = 'b';
    G.vertex[2] = 'c';
    G.vertex[3] = 'd';
    G.vertex[4] = 'e';
    G.vertex[5] = 'f';
    G.vertex[6] = 'g';

    G.edge[0][1] = 1;
    G.edge[1][0] = 1;

    G.edge[0][4] = 1;
    G.edge[4][0] = 1;

    G.edge[0][2] = 1;
    G.edge[2][0] = 1;

    G.edge[1][2] = 1;
    G.edge[2][1] = 1;

    G.edge[2][3] = 1;
    G.edge[3][2] = 1;

    G.edge[4][5] = 1;
    G.edge[5][4] = 1;

    G.edge[4][6] = 1;
    G.edge[6][4] = 1;
}

//***********************深度优先***********************
// 时间：
//      邻接矩阵：O(|v|**2)
//      邻接表：O(|v|+|E|)
// 空间： O(|v|)
void DFS(MGraph &g, int i) {
    visited[i] = true;
    cout << g.vertex[i] << " ";
    for (int j = 0; j < g.vertex_nums; ++j) {
        if (g.edge[i][j] == 1 && !visited[j]) {
            DFS(g, j);
        }
    }
}

void DFSTraverse(MGraph &g) {
    for (int i = 0; i < g.vertex_nums; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < g.vertex_nums; ++i) {
        if (!visited[i]) {
            DFS(g, i);
        }
    }
}


//***********************广度优先***********************
// 时间：
//      邻接矩阵：O(|v|**2)
//      邻接表：O(|v|+|E|)
// 空间： O(|v|)
void BFS(MGraph &g, int i, queue<char> &q) {
    q.push(i);
    visited[i] = true; //入队时就·设为true
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        cout << g.vertex[t] << ",";
        for (int j = 0; j < g.vertex_nums; ++j) {
            if (g.edge[i][j] == 1 && !visited[j]) {
                q.push(j);
                visited[j] = true;
            }
        }
    }
}

void BFSTraverse(MGraph &g) {
    for (int i = 0; i < g.vertex_nums; ++i) {
        visited[i] = false;
    }
    queue<char> q;
    for (int i = 0; i < g.vertex_nums; ++i) {
        if (!visited[i]) {
            BFS(g, i, q);
        }
    }
}

void BFSTraverse2(MGraph &g) {
    for (int i = 0; i < g.vertex_nums; ++i)
        visited[i] = false;
    queue<char> q;
    for (int i = 0; i < g.vertex_nums; ++i) {
        if (!visited[i]) {
            q.push(g.vertex[i]);
            visited[i] = true;
            while (!q.empty()) {
                cout << q.front() << ",";
                q.pop();
                for (int j = 0; j < g.vertex_nums; ++j) {
                    if (g.edge[i][j] == 1 && !visited[j]) {
                        q.push(g.vertex[j]);
                        visited[j] = true;
                    }
                }
            }
        }
    }
}

vector<int> BFS_MIN_Distance(MGraph &g, int n) {
    for (int i = 0; i < g.vertex_nums; ++i)
        visited[i] = false;
    vector<int> d(g.vertex_nums, 666); //d[i]表示 n 到 i 的距离
    queue<int> q;
    d[n] = 0;
    q.push(g.vertex[n]);
    visited[n] = true;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
//        cout << temp << ",";
        for (int i = 0; i < g.vertex_nums; ++i) {
            if (g.edge[n][i] == 1 && !visited[i]) {
                q.push(g.vertex[i]);
                visited[i] = true;
                d[i] = d[n] + 1;
            }
        }
    }
    return d;
}

int main(int argc, char *argv[]) {
    MGraph g;
    CreateGraph(g);
    BFSTraverse2(g);
//    vector<int> d = BFS_MIN_Distance(g, 0);
//    for (auto &c:d)
//        cout << c << ",";
    return 0;
}