#include <bits/stdc++.h>

using namespace std;

vector<int> GenerateRandom(int n){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(1, 500);

    vector<int> randomVector;

    for(int i = 0; i < n; i++){
        int randomNum = distribution(gen);
        randomVector.push_back(randomNum - 180);
    }

    return randomVector;
}

int MaxSub(vector<int>& A) {
    int max_ending_here = 0;
    int max_so_far = 0;

    for(int i = 0; i < A.size(); i++){
        max_ending_here = max(0, max_ending_here + A[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

void Display(vector<int>& Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout<<endl;
}

int main(){
    vector<int> Test = GenerateRandom(10000000);

    cout << "Array Test[]: ";
    Display(Test);

    cout << "Largest Possible Sum of a Subarray: " << MaxSub(Test) << endl;

    return 0;
}
