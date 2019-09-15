#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>

#define MaxVertexNum 100

using namespace std;

typedef struct {
    int vertexnums, edgenums;
    char Vertex[MaxVertexNum];
    int Edge[MaxVertexNum][MaxVertexNum];
} MGraph;

bool visited[MaxVertexNum];

void CreateGraph(MGraph &G) {
    G.vertexnums = 7;
    G.edgenums = 7;
    G.Vertex[0] = 'a';
    G.Vertex[1] = 'b';
    G.Vertex[2] = 'c';
    G.Vertex[3] = 'd';
    G.Vertex[4] = 'e';
    G.Vertex[5] = 'f';
    G.Vertex[6] = 'g';

    G.Edge[0][1] = 1;
    G.Edge[1][0] = 1;

    G.Edge[0][4] = 1;
    G.Edge[4][0] = 1;

    G.Edge[0][2] = 1;
    G.Edge[2][0] = 1;

    G.Edge[1][2] = 1;
    G.Edge[2][1] = 1;

    G.Edge[2][3] = 1;
    G.Edge[3][2] = 1;

    G.Edge[4][5] = 1;
    G.Edge[5][4] = 1;

    G.Edge[4][6] = 1;
    G.Edge[6][4] = 1;
}

void BFS(MGraph &g) {
    for (int i = 0; i < g.vertexnums; ++i)
        visited[i] = false;
    queue<char> q;
    for (int j = 0; j < g.vertexnums; ++j) {
        if (!visited[j]) {
            q.push(g.Vertex[j]);
            visited[j] = true;
            while (!q.empty()) {
                char temp = q.front();
                q.pop();
                cout << temp << ",";
                for (int i = 0; i < g.vertexnums; ++i) {
                    if (!visited[i] && g.Edge[j][i] == 1) {
                        q.push(g.Vertex[i]);
                        visited[i] = true;
                    }
                }
            }
        }
    }
}

//void DFSTraverse(MGraph &g, int i) {
//    visited[i] = true;
//    cout << g.Vertex[i] << ",";
//    for (int j = 0; j < g.vertexnums; ++j) {
//        if (g.Edge[i][j] == 1 && !visited[j])
//            DFSTraverse(g, j);
//    }
//}
//
//void DFS(MGraph &g) {
//    for (int i = 0; i < g.vertexnums; ++i)
//        visited[i] = false;
//    for (int i = 0; i < g.vertexnums; ++i) {
//        if (!visited[i]) {
//            DFSTraverse(g, i);
//        }
//    }
//}

void DFS(MGraph &g, int v) {
    visited[v] = true;
    cout << g.Vertex[v] << ",";
    for (int i = 0; i < g.vertexnums; ++i) {
        if (g.Edge[v][i] == 1 && !visited[i]) {
            DFS(g, i);
        }
    }
}

void DFSTraverse(MGraph &g) {
    for (int v = 0; v < g.vertexnums; ++v) {
        visited[v] = false;
    }
    for (int v = 0; v < g.vertexnums; ++v) {
        if (!visited[v]) {
            DFS(g, v);
        }
    }
}

int main() {
    MGraph g;
    CreateGraph(g);
    DFSTraverse(g);
    return 0;
}