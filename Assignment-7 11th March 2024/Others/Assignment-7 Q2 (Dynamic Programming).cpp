#include <bits/stdc++.h>

using namespace std;

struct Job{
    char id;
    int deadline, profit;
};

bool lessDeadline(Job a, Job b){
    return a.deadline < b.deadline;
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
    
    
    cout << DP(jobs);

    return 0;
}