#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>> &Graph, int src, vector<int> &curr){
    curr.push_back(src);

    vector<int> path = {};

    for(int i: Graph[src]){
        vector<int> newPath;

        DFS(Graph, i, newPath);

        if(newPath.size() > path.size()){
            path = newPath;
        }
    }

    for(int i: path){
        curr.push_back(i);
    }
}

vector<int> FindMaxPath(vector<vector<int>> &Graph){
    int n = Graph.size();
    vector<int> longest = {};

    for(int i = 0; i < n; i++){
        vector<int> newPath;

        DFS(Graph, i, newPath);
        
        if(newPath.size() > longest.size()){
            longest = newPath;
        }
    }

    return longest;
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
        {4},
        {2},
        {}
    };

    vector<int> MaxPath = FindMaxPath(adj);

    Display(MaxPath);

    return 0;
}