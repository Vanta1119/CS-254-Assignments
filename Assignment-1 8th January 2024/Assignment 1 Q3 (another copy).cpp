#include <bits/stdc++.h>
 
using namespace std;
 
int TSP(int i, int mask, int memo[][], vector<vector<int>> graph, int V){
    if(mask == ((1 << i) | 3)) return graph[1][i];

    if(memo[i][mask] != 0) return memo[i][mask];
 
    int res = INT_MAX; 

    for (int j = 1; j <= V; j++){
        if((mask & (1 << j)) && j != i && j != 1){
            res = min(res, TSP(j, mask & (~(1 << i))) + graph[j][i]);
        }
    }

    return memo[i][mask] = res;
}

int main(){
    int V = 4;
    int memo[V + 1][1 << (V + 1)];
    int ans = INT_MAX;

    vector<vector<int>> graph = {{0, 0, 0, 0, 0}, {0, 0, 10, 15, 20}, {0, 10, 0, 25, 25},{0, 15, 25, 0, 30}, {0, 20, 25, 30, 0}};

    for (int i = 1; i <= V; i++){
        ans = min(ans, TSP(i, (1 << (V + 1)) - 1, memo, graph, V) + graph[i][1]);
    }
 
    cout << "The Solution to Traveling Salesman Problem = " << ans << endl;

    return 0;
}