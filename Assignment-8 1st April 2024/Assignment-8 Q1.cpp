#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node)
        return node;
    return findParent(parent[node], parent);
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int uSet = findParent(u, parent);
    int vSet = findParent(v, parent);

    if (rank[uSet] < rank[vSet])
        parent[uSet] = vSet;
    else if (rank[vSet] < rank[uSet])
        parent[vSet] = uSet;
    else {
        parent[vSet] = uSet;
        rank[uSet]++;
    }
}

bool compareEdges(Edge a, Edge b) {
    return a.weight > b.weight;
}

vector<Edge> kruskalMST(int V, vector<Edge>& edges) {
    vector<Edge> MST;
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edgeCount = 0;
    for (Edge edge : edges) {
        if (findParent(edge.src, parent) != findParent(edge.dest, parent)) {
            MST.push_back(edge);
            unionSets(edge.src, edge.dest, parent, rank);
            edgeCount++;
        }
        if (edgeCount == V - 1)
            break;
    }
    return MST;
}

int main() {
    int E, V;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    vector<Edge> MST = kruskalMST(V, edges);

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (Edge edge : MST) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}
