#include <bits/stdc++.h>

using namespace std;

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

vector<vector<int>> MatrixRandom(int m, int n){
    vector<vector<int>> Matrix;

    for(int i = 0; i < m; i++){
        Matrix.push_back(GenerateRandom(n));
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

int BFS(vector<vector<int>>& matrix, int row, int col, int m, int n) {
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    queue<pair<int, int>> q;

    q.push({row, col});

    matrix[row][col] = 0;

    int size = 0;

    while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        size++;

        for(pair<int, int> i: directions){
            int x = current.first + i.first;
            int y = current.second + i.second;

            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] == 1){
                matrix[x][y] = 0;
                q.push({x, y});
            }
        }
    }

    return size;
}

int LargestRegionSize(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int maxRegion = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; ++j){
            if(matrix[i][j] == 1){
                int region = BFS(matrix, i, j, m, n);
                maxRegion = max(maxRegion, region);
            }
        }
    }
    return maxRegion;
}

int main() {
    vector<vector<int>> Test = MatrixRandom(10000, 10000);

    Display(Test);

    cout << "Size of the Biggest Region: " << LargestRegionSize(Test) << endl;

    return 0;
}