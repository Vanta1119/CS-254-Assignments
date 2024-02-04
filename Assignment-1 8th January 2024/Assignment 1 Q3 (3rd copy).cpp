#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

int TSP(int i, int mask, vector<vector<int>>& memo, const vector<vector<int>>& graph, int V) {
    if (mask == (1 << (V + 1)) - 1) return graph[i][1];

    if(memo[i][mask] != 0) return memo[i][mask];

    int res = INF;

    for(int j = 1; j <= V; j++){
        if((mask & (1 << j)) && j != i && j != 1){
            res = min(res, TSP(j, mask & (~(1 << j)), memo, graph, V) + graph[i][j]);
        }
    }

    return memo[i][mask] = res;
}

int main() {
    int V = 4;
    vector<vector<int>> memo(V + 1, vector<int>(1 << (V + 1), 0));
    int ans = INF;

    vector<vector<int>> graph = {{0, 0, 0, 0, 0}, {0, 0, 12, 42, 35}, {0, 20, 0, 30, 34}, {0, 42, 30, 0, 12}, {0, 35, 34, 12, 0}};

    for(int i = 2; i <= V; i++){
        ans = min(ans, TSP(i, (1 << (V + 1)) - 1 ^ (1 << i), memo, graph, V) + graph[1][i]);
    }

    cout << "The Solution to Traveling Salesman Problem = " << ans << endl;

    return 0;
}
