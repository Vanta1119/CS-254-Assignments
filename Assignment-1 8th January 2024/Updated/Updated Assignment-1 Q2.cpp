#include <bits/stdc++.h>

using namespace std;
#define V 4

int travllingSalesmanProblem(int graph[][V], int s){
	vector<int> vertex;
	for (int i = 0; i < V; i++)
		if (i != s)
			vertex.push_back(i);

	int min_path = INT_MAX;
	do {
		int current_pathweight = 0;
		int k = s;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}
		current_pathweight += graph[k][s];
		min_path = min(min_path, current_pathweight);

	} while (next_permutation(vertex.begin(), vertex.end()));

	return min_path;
}

int main(){
	ifstream inputFile("input3.txt");
	ofstream outputFile("output3.txt");

	if (!inputFile.is_open() || !outputFile.is_open()) {
		cout << "Error opening files!" << endl;
		return 1;
	}

	int graph[V][V];

	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			inputFile >> graph[i][j];

	int s = 0;
	int result = travllingSalesmanProblem(graph, s);

	outputFile << result << endl;

	inputFile.close();
	outputFile.close();

	cout << "Output written to output3.txt" << endl;

	return 0;
}
