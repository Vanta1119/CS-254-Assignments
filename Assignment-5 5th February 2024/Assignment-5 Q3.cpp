#include <bits/stdc++.h>

using namespace std;

bool isBipartitePart(vector<vector<int>> graph, int src, vector<int> colorArr) {
	colorArr[src] = 1;

	queue<int> q;
	int n = graph.size();

	q.push(src);

	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int v = 0; v < n; v++){
			if(graph[u][v] && colorArr[v] == -1){
				colorArr[v] = 1 - colorArr[u];
				q.push(v);
			}

			else if (graph[u][v] && colorArr[v] == colorArr[u]) return false;
		}
	}

	return true;
}

bool isBipartite(vector<vector<int>> graph){
	int n = graph.size();
	vector<int> colorArr(n);

	for(int i = 0; i < n; i++){
		colorArr[i] = -1;
    }

	for(int i = 0; i < n; i++){
		if(colorArr[i] == -1){
			if(isBipartitePart(graph, i, colorArr) == false){
				return false;
            }
        }
    }

	return true;
}

bool canBeDividedInTwoCliques(vector<vector<int>> graph){
	int n = graph.size();
	vector<vector<int>> complementGraph(n, vector<int>(n));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			complementGraph[i][j] = (i != j) ? !graph[i][j] : 0;
        }
    }

	return isBipartite(complementGraph);
}

int main() {
	vector<vector<int>> graph = {
		{0, 1, 1, 1, 0},
		{1, 0, 1, 0, 0},
		{1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1},
		{0, 0, 0, 1, 0}
	};

	canBeDividedInTwoCliques(graph) ? cout << "Yes" << endl : cout << "No" << endl;

	return 0;
}
