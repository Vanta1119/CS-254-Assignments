#include <bits/stdc++.h>

using namespace std;

struct QueueEntry{
	int vertex;
	int distance;
};

vector<int> ConvertBoard(vector<vector<int>> Board){
	int m = Board.size(), n = Board[0].size();
	vector<int> Line;

	int row, col;

	for(int i = 0; i < m; i++){
		row = i / n;

		if(row % 2 == 0){
			for(int j = 0; j < n; j++){
				Line.push_back(Board[i][j]);
			}
		}
		else{
			for(int j = n - 1; j >= 0; j--){
				Line.push_back(Board[i][j]);
			}
		}
	}

	return Line;
}

int GetDiceThrows(vector<vector<int>> Board){
	vector<int> moves = ConvertBoard(Board);
	int n = moves.size();
	
	vector<bool> visited(n);
	queue<QueueEntry> q;

	visited[0] = true;

	QueueEntry start = {0, 0}, current;
	q.push(start);

	while(!q.empty()){
		current = q.front();
		int v = current.vertex;

		if(v == n - 1) break;

		q.pop();

		for(int j = v + 1; j <= (v + 6) && j < n; j++){
			if(!visited[j]){
				QueueEntry next;
				next.distance = (current.distance + 1);

				visited[j] = true;
				next.vertex = (moves[j] != -1) ? moves[j] : j;
				q.push(next);
			}
		}
	}
    
	return current.distance;
}

void Display(vector<vector<int>> Matrix){
    for(int i = 0; i < Matrix.size(); i++){
        for(int j = 0; j < Matrix[0].size(); j++){
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int main() {
	vector<vector<int>> Board = {
		{-1, -1, -1, 0, -1},
		{8, -1, -1, -1, -1},
		{28, 6, -1, 3, -1},
		{25, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1},
		{-1, -1, 21, -1, 7},
	};

    Display(Board);

	cout << "Minimum number of dice throws required is: " << GetDiceThrows(Board) << endl;
	return 0;
}
