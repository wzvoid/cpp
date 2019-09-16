#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>

#define MaxVertexNum 50

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

void BFSTraverse(MGraph &g) {
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

void DFS(MGraph &g, int i) {
    visited[i] = true;
    cout << g.Vertex[i] << ",";
    for (int j = 0; j < g.vertexnums; ++j) {
        if (g.Edge[i][j] == 1 && !visited[j])
            DFS(g, j);
    }
}

void DFSTraverse(MGraph &g) {
    for (int i = 0; i < g.vertexnums; ++i)
        visited[i] = false;
    int count = 0;
    for (int i = 0; i < g.vertexnums; ++i) {
        if (!visited[i]) {
            DFS(g, i);
            ++count;
        }
    }
    cout << endl << "Connected Component: " << count;
}

int main() {
    MGraph g;
    CreateGraph(g);
    DFSTraverse(g);
    return 0;
}