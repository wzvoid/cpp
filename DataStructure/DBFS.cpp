//
// Created by 王振 on 2019/8/26.
//
#include <iostream>
#include <stack>
#include <queue>

#define MaxVertexNum 100

using namespace std;

//邻接表
typedef struct {
    int vertexnums, edgenums;
    char Vertex[MaxVertexNum];
    int Edge[MaxVertexNum][MaxVertexNum];
} MGraph;

//邻接矩阵
typedef struct {
    int vertexnums, edgenums;

} LGraph;

bool visited[MaxVertexNum];

void CreateGraph(MGraph &G) {
    G.vertexnums = 4;
    G.edgenums = 8;
    G.Vertex[0] = 'a';
    G.Vertex[1] = 'c';
    G.Vertex[2] = 'b';
    G.Vertex[3] = 'd';
    G.Edge[0][1] = 1;
    G.Edge[0][2] = 1;
    G.Edge[1][0] = 1;
    G.Edge[1][3] = 1;
    G.Edge[2][0] = 1;
    G.Edge[2][3] = 1;
    G.Edge[3][1] = 1;
    G.Edge[3][2] = 1;
}

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

void BFS(MGraph &g, int v, queue<int> &q) {
    q.push(v);
    visited[v] = true; //入队时就设为true
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        cout << g.Vertex[t] << ",";
        for (int i = 0; i < g.vertexnums; ++i) {
            if (g.Edge[v][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFSTraverse(MGraph &g) {
    for (int v = 0; v < g.vertexnums; ++v) {
        visited[v] = false;
    }
    queue<int> q;
    for (int v = 0; v < g.vertexnums; ++v) {
        if (!visited[v]) {
            BFS(g, v, q);
        }
    }
}

int main(int argc, char *argv[]) {
    MGraph g;
    CreateGraph(g);
    BFSTraverse(g);
    return 0;
}