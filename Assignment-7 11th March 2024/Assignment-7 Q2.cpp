#include <bits/stdc++.h>

using namespace std;

struct Job{
    char id;
    int deadline, profit;
};

bool moreProfit(Job a, Job b){
    return a.profit > b.profit;
}

bool lessDeadline(Job a, Job b){
    return a.deadline < b.deadline;
}

int Greedy(vector<Job>& jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), moreProfit);

    vector<int> result(n);
    vector<bool> rank(n);

    for(int i = 0; i < n; i++){
        for(int j = min(n, jobs[i].deadline) - 1; j >= 0; j--){
            if(!rank[j]){
                result[j] = i;
                rank[j] = 1;
                break;
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans += jobs[result[i]].profit * rank[i];
    }
    
    return ans;
}

int DP(vector<Job>& jobs){
    sort(jobs.begin(), jobs.end(), lessDeadline);

    int n = jobs.size();
    int maxDeadline = jobs[n-1].deadline;
    vector<int> dp(maxDeadline+1, 0);

    for(int i = 0; i < n; i++){
        for(int j = jobs[i].deadline; j > 0; j--){
            if(dp[j] < dp[j-1] + jobs[i].profit){
                dp[j] = dp[j-1] + jobs[i].profit;
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<Job> jobs = {{'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30}};

    cout << "Greedy Solution: " << Greedy(jobs);
    cout << "Dynamic Programming Solution: " << DP(jobs);

    return 0;
}