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

vector<vector<int>> MatrixMultiplication(vector<vector<int>> A, vector<vector<int>> B){
    int m = A[0].size(), n = B.size();
    int x = A.size(), y = B[0].size();

    if(m != n){
        cout << "Invalid Input!" << endl;
        return {{-80085}};
    }

    vector<vector<int>> M;

    for(int i = 0; i < )

    return M;
}

// void Display(vector<vector<int>> Matrix){
//     for(int i = 0; i < Matrix.size(); i++){
//         for(int j = 0; j < Matrix[0].size(); j++){
//             int num = Matrix[i][j];

//             if(j == 0){
//                 cout << num << " "; 
//                 continue;
//             }
            
//             if(num >= 0 && num < 10){
//                 cout << "   " << num << " "; 
//                 continue;
//             } 
//             else if(num < 0 && num > -10){
//                 cout << " " << num << " "; 
//                 continue;
//             }
//             else{
//                 if(num == -10){
//                     cout << num << " "; 
//                     continue;
//                 }
//                 else{
//                     cout << " " << num << " "; 
//                     continue;
//                 }                
//             } 
//         }

//         cout << endl;
//     }

//     cout<<endl;
// }

int main(){
    vector<vector<int>> TestA = MatrixRandom(4, 4);
    vector<vector<int>> TestB = MatrixRandom(4, 4);

    cout << "Matrix TestA[][]: " << endl;
    Display(TestA);

    cout << "Matrix TestB[][]: " << endl;
    Display(TestB);

    return 0;
}