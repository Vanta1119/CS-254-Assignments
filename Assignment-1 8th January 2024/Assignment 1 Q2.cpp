#include <bits/stdc++.h>

using namespace std;

int Knapsack(vector<int> w, vector<int> val, int wt, int n){
    vector<vector<int>> dp(n + 1 , vector<int> (wt + 1, 0));  

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= wt; j++){
            if(w[i-1] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(val[i-1] + dp[i-1][j - w[i-1]], dp[i-1][j]);
        }
    }

    return dp[n][wt];
};

int main(){
    vector<int> weights = {2, 5, 7, 3, 1}, values = {10, 20, 15, 7, 5};
    int maxWeight = 10;
    
    cout << Knapsack(weights, values, maxWeight, weights.size());

    return 0;
}
