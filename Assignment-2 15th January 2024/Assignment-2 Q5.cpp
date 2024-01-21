#include <bits/stdc++.h>

using namespace std;

vector<int> GenerateRandom(int n){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(1, 500);

    vector<int> randomVector;

    for(int i = 0; i < n; i++){
        int randomNum = distribution(gen);
        randomVector.push_back(randomNum);
    }

    return randomVector;
}

vector<int> Minima(vector<int> A){  
    vector<int> ind;

    for(int i = 1; i < A.size() - 1; i++){
        if(A[i] < A[i + 1] && A[i] < A[i + 1]){
            ind.push_back(i);
        }
    }

    cout << endl << "First Index: " <<  ind[0] << endl << "Second Index: " << ind[1] << endl;

    return ind;
}

void Display(vector<int> Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout<<endl;
}

int main(){
    vector<int> Test = GenerateRandom(500);

    Display(Test);
    Minima(Test);

    return 0;
}