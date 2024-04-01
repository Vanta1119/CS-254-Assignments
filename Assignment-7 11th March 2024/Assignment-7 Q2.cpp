#include <bits/stdc++.h>

using namespace std;

struct Job{
    char id;
    int deadline, profit;
};

bool moreProfit(Job a, Job b){
    return a.profit < b.profit;
}

bool lessDeadline(Job a, Job b){
    return a.deadline > b.deadline;
}

int Queue(vector<Job>& jobs){
    sort(jobs.begin(), jobs.end(), lessDeadline);
    priority_queue<Job, vector<Job>, function<bool(Job, Job)>> pq(moreProfit);

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
    // vector<Job> jobs = {{'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30}};
    vector<Job> jobs = {{'a', 5, 300}, {'b', 3, 200}, {'c', 3, 100}, {'d', 1, 50}, {'e', 2, 50}};

    cout << "Greedy Solution: " << Queue(jobs) << endl;

    return 0;
}