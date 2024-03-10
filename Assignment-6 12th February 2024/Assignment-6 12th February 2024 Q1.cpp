#include <bits/stdc++.h>

using namespace std;

vector<int> TopologicalSort(vector<vector<int>> &Graph){
    int n = Graph.size();

    queue<int> Q;
    vector<int> deg(n), ans;

    for(int i = 0; i < n; i++) 
        for(int x: Graph[i]) deg[x]++;
    
    for(int i = 0; i < n; i++){
        if(!deg[i]) Q.push(i);
    } 
        
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        ans.push_back(node);
        
        for(int child: Graph[node]) {
            deg[child]--;

            if(!deg[child]){
                Q.push(child);    
            }       
        }
    }

    return ans;
}

void Display(vector<int>& Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout << endl;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},
        {3, 4},
        {3},
        {},
        {2}
    };

    vector<int> Topological = TopologicalSort(adj);

    Display(Topological);

    return 0;
}