#include <bits/stdc++.h>
using namespace std;

struct QueueEntry {
	int vertex;
	int distance;
};

int GetDiceThrows(vector<int> moves, int N) {
	bool* visited = new bool[N]();
	queue<QueueEntry> q;

	visited[0] = true;

	QueueEntry start = { 0, 0 };
	q.push(start);

	QueueEntry current;
	while (!q.empty()) {
		current = q.front();
		int v = current.vertex;

		if(v == N - 1) break;

		q.pop();

		for(int j = v + 1; j <= (v + 6) && j < N; ++j){
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

void Display(vector<int> Matrix){
    for(int i = 0; i < Matrix.size(); i++){
        cout << Matrix[i] << " ";
    }

    cout << endl;
}

int main() {
	int BoardSize = 30;
	vector<int> Board(BoardSize, -1);

    // Ladders
	Board[2] = 21;
	Board[4] = 7;
	Board[10] = 25;
	Board[19] = 28;

    // Snakes
	Board[26] = 0;
	Board[20] = 8;
	Board[16] = 3;
	Board[18] = 6;

    Display(Board);

	cout << "Minimum number of dice throws required is " << GetDiceThrows(Board, BoardSize) << endl;
	return 0;
}
