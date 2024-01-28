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

int MaxSub(vector<int> A, int n, int csum){
    if(n == 0) return 0;
    if(A[n-1] >= 0){
        int sum = MaxSub(A, n-1, csum + A[n-1]);

        return max(sum, csum);
    }
    else{
        int sum1 = MaxSub(A, n-1, 0);
        int sum2 = MaxSub(A, n-1, csum + A[n-1]);

        return max({sum1, sum2, csum});
    }

    return csum;
}

void Display(vector<int> Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout<<endl;
}

int main(){
    vector<int> Test = GenerateRandom(10);

    cout << "Array Test[]: ";
    Display(Test);

    cout << "Largest Possible Sum of a Subarray: " << MaxSub(Test, Test.size(), 0) << endl;

    return 0;
}