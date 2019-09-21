#include <iostream>

using namespace std;

int visted[100];

typedef struct EdgeNode {
    int adjvex;
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode {
    char data;
    EdgeNode *firstedge;
} VertexNode, AdjList[100];

typedef struct {
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList;

class AdjacencyList {
public:
    void CreateALGraph(GraphAdjList *G);

    void ShowALGraph(GraphAdjList *G);

    void DFS(GraphAdjList *G, int i);

    void DFSTraverse(GraphAdjList *G);

    void Test();
};

void AdjacencyList::CreateALGraph(GraphAdjList *G) {
    int i, j, k;
    EdgeNode *e;
    cout << "输入顶点数和边数" << endl;
    cin >> G->numVertexes >> G->numEdges;
    for (i = 0; i < G->numVertexes; i++) {
        cin >> G->adjList[i].data;
        G->adjList[i].firstedge = nullptr;
    }
    for (k = 0; k < G->numEdges; k++) {
        cout << "输入边（vi,vj）上的顶点序号" << endl;
        cin >> i >> j;
        e = new EdgeNode;
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;
        e = new EdgeNode;
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}

void AdjacencyList::Test() {
    cout << "ALL IS OK." << endl;
}

void AdjacencyList::ShowALGraph(GraphAdjList *G) {
    for (int i = 0; i < G->numVertexes; i++) {
        cout << "顶点" << i << ": " << G->adjList[i].data << "--firstedge--";
        EdgeNode *p = new EdgeNode;
        p = G->adjList[i].firstedge;
        while (p) {
            cout << p->adjvex << "--Next--";
            p = p->next;
        }
        cout << "--NULL" << endl;
    }

}

void AdjacencyList::DFS(GraphAdjList *G, int i) {
    EdgeNode *p;
    visted[i] = 1;
    cout << G->adjList[i].data << "--";
    p = G->adjList[i].firstedge;
    while (p) {
        if (!visted[p->adjvex]) {
            DFS(G, p->adjvex);
        }
        p = p->next;
    }

}

void AdjacencyList::DFSTraverse(GraphAdjList *G) {
    cout << "深度优先遍历结果为：" << endl;
    for (int i = 0; i < G->numVertexes; i++) {
        visted[i] = 0;
    }
    for (int i = 0; i < G->numVertexes; i++) {
        if (visted[i] == 0) {
            DFS(G, i);
        }
    }
}


int main() {
    AdjacencyList adjacencyList;
    auto *GA = new GraphAdjList;
    adjacencyList.Test();
    adjacencyList.CreateALGraph(GA);
    adjacencyList.ShowALGraph(GA);
    adjacencyList.DFSTraverse(GA);
    return 0;
}

