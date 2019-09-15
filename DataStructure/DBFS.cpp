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
void DFS(MGraph &g, int v) {
    visited[v] = true;
    cout << g.vertex[v] << ",";
    for (int i = 0; i < g.vertex_nums; ++i) {
        if (g.edge[v][i] == 1 && !visited[i]) {
            DFS(g, i);
        }
    }
}

void DFSTraverse(MGraph &g) {
    for (int v = 0; v < g.vertex_nums; ++v) {
        visited[v] = false;
    }
    for (int v = 0; v < g.vertex_nums; ++v) {
        if (!visited[v]) {
            DFS(g, v);
        }
    }
}


//***********************广度优先***********************
void BFS(MGraph &g, int v, queue<int> &q) {
    q.push(v);
    visited[v] = true; //入队时就设为true
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        cout << g.vertex[t] << ",";
        for (int i = 0; i < g.vertex_nums; ++i) {
            if (g.edge[v][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

//void BFSTraverse(MGraph &g) {
//    for (int v = 0; v < g.vertex_nums; ++v) {
//        visited[v] = false;
//    }
//    queue<int> q;
//    for (int v = 0; v < g.vertex_nums; ++v) {
//        if (!visited[v]) {
//            BFS(g, v, q);
//        }
//    }
//}

void BFSTraverse(MGraph &g) {
    for (int i = 0; i < g.vertex_nums; ++i) {
        visited[i] = false;
    }
    queue<int> q;
    for (int i = 0; i < g.vertex_nums; ++i) {
        if (!visited[i]) {
            q.push(g.vertex[i]);
            visited[i] = true;
            while (!q.empty()) {
                cout << (char) q.front() << ",";
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

int main(int argc, char *argv[]) {
    MGraph g;
    CreateGraph(g);
    BFSTraverse(g);
    return 0;
}