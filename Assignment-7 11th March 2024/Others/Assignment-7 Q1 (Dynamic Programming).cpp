#include <bits/stdc++.h>

using namespace std;

int DP(vector<int> values, vector<int> weights, int W){
    vector<vector<int>> dp(n + 1, vector<int>(WeightLimit + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= WeightLimit; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "Maximum value: " << dp[n][WeightLimit] << endl;
}

int main() {
    vector<int> weights(n), values(n);
    
    int n, WeightLimit;
    cin >> n >> WeightLimit;
    
    return 0;
}
