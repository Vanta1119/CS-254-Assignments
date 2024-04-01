#include <bits/stdc++.h>

using namespace std;

struct Job{
    char id;
    int deadline, profit;
};

bool moreProfit(Job a, Job b){
    return a.profit > b.profit;
}

bool lessProfit(Job a, Job b){
    return a.profit < b.profit;
}

bool lessDeadline(Job a, Job b){
    return a.deadline > b.deadline;
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
        if(rank[i]){
            ans += jobs[result[i]].profit * rank[i];
            cout << "Picked: " << jobs[result[i]].id << endl;
        }
    }
    
    return ans;
}

int Queue(vector<Job>& jobs){
    sort(jobs.begin(), jobs.end(), lessDeadline);
    priority_queue<Job, vector<Job>, function<bool(Job, Job)>> pq(lessProfit);

    int n = jobs[0].deadline, m = jobs.size();
    int left = 0, ans = 0;

    for(int i = n; i > 0; i--){
        if(left == m) break;
        while(left < m && jobs[left].deadline == i){
            pq.push(jobs[left++]);
        }

        if(!pq.empty()){
            Job best = pq.top();
            cout << "Picked: " << best.id << endl;
            pq.pop();
            ans += best.profit;
        }
    }

    return ans;
}

int main() {
    vector<Job> jobs = {{'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30}};

    cout << "Greedy Solution: " << Greedy(jobs) << endl;
    cout << "Queue Solution: " << Queue(jobs) << endl;

    return 0;
}