#include <bits/stdc++.h>

using namespace std;

vector<int> GenerateRandom(int n){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(0, 9);

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

    cout<<endl;
}

vector<vector<int>> MatrixAddition(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int>> C(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; ++j){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> MatrixMultiplication(vector<vector<int>>& A, vector<vector<int>>& B){
    int n = A.size();
    int m = A[0].size();

    if (n == 1 && m == 1) {
        vector<vector<int>> C(1, vector<int>(1, 0));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int half_size = n / 2;

    vector<vector<int>> A11(half_size, vector<int>(half_size));
    vector<vector<int>> A12(half_size, vector<int>(half_size));
    vector<vector<int>> A21(half_size, vector<int>(half_size));
    vector<vector<int>> A22(half_size, vector<int>(half_size));

    vector<vector<int>> B11(half_size, vector<int>(half_size));
    vector<vector<int>> B12(half_size, vector<int>(half_size));
    vector<vector<int>> B21(half_size, vector<int>(half_size));
    vector<vector<int>> B22(half_size, vector<int>(half_size));

    for(int i = 0; i < half_size; i++){
        for(int j = 0; j < half_size; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half_size];
            A21[i][j] = A[i + half_size][j];
            A22[i][j] = A[i + half_size][j + half_size];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half_size];
            B21[i][j] = B[i + half_size][j];
            B22[i][j] = B[i + half_size][j + half_size];
        }
    }

    vector<vector<int>> C11 = MatrixAddition(MatrixMultiplication(A11, B11), MatrixMultiplication(A12, B21));
    vector<vector<int>> C12 = MatrixAddition(MatrixMultiplication(A11, B12), MatrixMultiplication(A12, B22));
    vector<vector<int>> C21 = MatrixAddition(MatrixMultiplication(A21, B11), MatrixMultiplication(A22, B21));
    vector<vector<int>> C22 = MatrixAddition(MatrixMultiplication(A21, B12), MatrixMultiplication(A22, B22));

    vector<vector<int>> C(n, vector<int>(m));

    for(int i = 0; i < half_size; i++){
        for(int j = 0; j < half_size; j++){
            C[i][j] = C11[i][j];
            C[i][j + half_size] = C12[i][j];
            C[i + half_size][j] = C21[i][j];
            C[i + half_size][j + half_size] = C22[i][j];
        }
    }

    return C;
}

int main(){
    vector<vector<int>> TestA = MatrixRandom(4, 4);
    vector<vector<int>> TestB = MatrixRandom(4, 4);

    cout << "Matrix TestA[][]: " << endl;
    Display(TestA);

    cout << "Matrix TestB[][]: " << endl;
    Display(TestB);

    vector<vector<int>> result = MatrixMultiplication(TestA, TestB);
    cout << "Result of Matrix Multiplication: " << endl;
    Display(result);

    return 0;
}
