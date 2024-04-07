#include <bits/stdc++.h>

using namespace std;

struct Item{
    string name;
    int value, weight;
};

bool moreValue(const Item &a, const Item &b){
    return float(a.value) / float(a.weight) > float(b.value) / float(b.weight);
}

void Display(vector<string> Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout<<endl;
}

pair<vector<string>, int> Greedy(vector<Item> &items, int W){
    int n = items.size();

    sort(items.begin(), items.end(), moreValue);

    vector<string> ans;
    int res = 0;

    for(Item item: items){
        if(W >= item.weight){
            W -= item.weight;
            res += item.value;
            ans.push_back(item.name);
        }
    }

    pair<vector<string>, int> p;
    p.first = ans;
    p.second = res;

    Display(ans);

    return p;
}

pair<vector<string>, int> DP(vector<Item> items, int W){
    int n = items.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    vector<vector<vector<string>>> dat(n + 1, vector<vector<string>>(W + 1, vector<string>()));

    for(int i = 1; i <= n; i++){
        for(int w = 1; w <= W; w++){
            if(items[i-1].weight <= w){
                int a = items[i-1].value + dp[i-1][w-items[i-1].weight], b = dp[i-1][w];
                dp[i][w] = max(a, b);

                if(a > b){
                    dat[i][w] = dat[i-1][w-items[i-1].weight];
                    dat[i][w].push_back(items[i-1].name);
                }
                else{
                    dat[i][w] = dat[i-1][w];
                }
            }
            else{
                dp[i][w] = dp[i-1][w];
                dat[i][w] = dat[i-1][w];
            }
        }
    }

    pair<vector<string>, int> p;
    p.first = dat[n][W];
    p.second = dp[n][W];

    Display(p.first);

    return p;
}

int main(){
    int WeightLimit = 10;
    vector<Item> Items = {{"i1", 2, 10}, {"i2", 5, 20}, {"i3", 7, 15}, {"i4", 3, 7}, {"i5", 1, 5}};

    cout << "Greedy Solution: " << Greedy(Items, WeightLimit).second << endl;
    cout << "Dynamic Programming Solution: " << DP(Items, WeightLimit).second << endl;
    
    return 0;
}