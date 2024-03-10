#include <bits/stdc++.h>

using namespace std;

int findMinKey(const vector<int>& key, const vector<bool>& mstSet, int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

int primMST(vector<vector<int>>& graph, int V, int startNode, int endNode) {
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[startNode] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int mstWeight = 0;
    for (int i = 0; i < V; ++i) {
        mstWeight += key[i];
    }

    return mstWeight;
}

int minimumAns(vector<vector<int>> graph, int V, int startNode){
    int ans = INT_MAX;

    for(int i = 0; i != startNode, i < V; i++){
        int mstWeight = primMST(graph, V, startNode, i);

        ans = min(ans, mstWeight + graph[startNode][i]);
    }

    return ans;
}

int main() {
    int V = 4;

    vector<vector<int>> graph = {{0, 12, 42, 35}, {20, 0, 30, 34}, {42, 30, 0, 12}, {35, 34, 12, 0}};

    int startNode = 0;
    int ans = minimumAns(graph, V, startNode);
 
    cout << "Traveling Salesman Problem Answer: " << ans << endl;

    return 0;
}
