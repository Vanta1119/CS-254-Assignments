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

int MaxSub(vector<int> A, int n, int csum, vector<int> &ans){
    if(n == 0) return 0;
    if(A[n-1] >= 0){
        ans.push_back(csum + A[n-1]);
        return MaxSub(A, n-1, csum + A[n-1], ans);
    }
    else{
        ans.push_back(csum + A[n-1]);
        int s1 = MaxSub(A, n-1, 0, ans);
        int s2 = MaxSub(A, n-1, csum + A[n-1], ans);

        return max(s1, s2);
    }

    return csum;
}

int Max(vector<int> ans){
    int ma = ans[0];

    for(auto i : ans){
        ma = max(ma, i);
    }

    return ma;
}

// int MaxSub(vector<int> A, int n, int csum){
//     if(n == 0) return 0;
//     if(A[n-1] >= 0){
//         cout << csum << " POSITIVE " << A[n-1] << endl;
//         return MaxSub(A, n-1, csum + A[n-1]);
//     }
//     else{
//         cout << csum << " NEGATIVE " << A[n-1] << endl;
//         int s1 = MaxSub(A, n-1, 0);
//         int s2 = MaxSub(A, n-1, csum + A[n-1]);

//         return max(s1, s2);
//     }

//     return csum;
// }

// int MaxSub(vector<int> A, int n, int csum, int mtl){
//     if(n == 0) return 0;
//     if(A[n-1] >= 0){
//         int a = MaxSub(A, n-1, csum + A[n-1], mtl);
//         mtl = max(mtl, a);

//         return mtl;
//     }
//     else{
//         int s1 = MaxSub(A, n-1, 0, mtl);
//         int s2 = MaxSub(A, n-1, csum + A[n-1], mtl);

//         mtl = max({mtl, s1, s2});

//         return mtl;
//     }

//     return -1;
// }

void Display(vector<int> Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout<<endl;
}

int main(){
    vector<int> Test = GenerateRandom(10);
    vector<int> ans;

    cout << "Array Test[]: ";
    Display(Test);

    MaxSub(Test, Test.size(), 0, ans);
    cout << "Largest Possible Sum of a Subarray: " << Max(ans);

    return 0;
}