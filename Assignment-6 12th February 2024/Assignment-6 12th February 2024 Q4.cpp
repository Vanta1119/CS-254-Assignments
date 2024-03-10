#include <bits/stdc++.h>

using namespace std;

bool DFS(vector<vector<int>> &Graph, int src, int length){
    int n = Graph.size();
    if(length > n){
        return true;
    }

    bool loop = false;

    for(int i: Graph[src]){
        vector<int> newPath;

        bool inLoop = DFS(Graph, i, length+1);

        if(inLoop) return true;
    }

    return loop;
}

void hasLoop(vector<vector<int>> &Graph){
    int n = Graph.size();
    bool loop = false;

    for(int i = 0; i < n; i++){
        bool curr = DFS(Graph, i, 0);

        if(curr){
            loop = curr;
            break;
        }
    }

    cout << (loop ? "At least one loop exists." : "No loop exists.") << endl;
}

int main() {
    vector<vector<int>> Looped = {
        {1},
        {2, 3},
        {4},
        {0},
        {}
    };

    hasLoop(Looped);
    

    vector<vector<int>> Unlooped = {
        {1},
        {2, 3},
        {4},
        {4},
        {}
    };

    hasLoop(Unlooped);

    return 0;
}
