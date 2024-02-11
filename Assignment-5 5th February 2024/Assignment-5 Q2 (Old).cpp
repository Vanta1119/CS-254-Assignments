#include <bits/stdc++.h>
using namespace std;

int BFS(int n, vector<pair<int, int>> &idxs, vector<vector<int>> &board) {
    vector<int> dis(n * n + 1, -1);

    queue<int> qu;
    dis[1] = 0;
    qu.push(1);

    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();

        int m = min(cur + 6, n * n);
        for (int cell = cur + 1; cell <= m; ++cell) {
            auto [row, col] = idxs[cell];
            int nxt = board[row][col] != -1 ? board[row][col] : cell;

            if (dis[nxt] == -1) {
                dis[nxt] = dis[cur] + 1;
                qu.push(nxt);
            }
        }
    }

    return dis[n * n];
}

int SnakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    
    vector<pair<int, int>> idxs(n * n + 1);
    int idx = 1;
    
    vector<int> cols(n);
    iota(cols.begin(), cols.end(), 0);
    
    for (int row = n - 1; row >= 0; --row) {
        for (auto col : cols)
            idxs[idx++] = {row, col};
        
        reverse(cols.begin(), cols.end());
    }

    return BFS(n, idxs, board);
}

vector<int> GenerateRandom(int n){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(0, 1);

    vector<int> randomVector;

    for(int i = 0; i < n; i++){
        int randomNum = distribution(gen);
        randomVector.push_back(randomNum);
    }

    return randomVector;
}

int GenerateRange(int begin, int end){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(begin, end);

    int random = distribution(gen);


    return random;
}

vector<vector<int>> BoardRandom(int m, int n){
    vector<vector<int>> Matrix(m, vector<int>(n));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            int pick = GenerateRange(1, 10);

            if(pick == 1 && j != m - 1){
                int ladder = GenerateRange(j, n - 1);
                Matrix[i][j] = ladder;
            }
            else if(pick == 2 && j != 0){
                int snake = GenerateRange(j, n - 1);
                Matrix[i][j] = snake;
            }
            else{
                Matrix[i][j] = -1;
            }
        }
    }

    return Matrix;
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
    vector<vector<int>> Board = BoardRandom(6, 6);

    Display(Board);

	cout << "Minimum Moves Required: " << SnakesAndLadders(Board) << endl;

	return 0;
}