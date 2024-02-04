#include <bits/stdc++.h>

using namespace std;

vector<int> GenerateRandom(int n){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(0, 9);

    vector<int> randomVector;

    for(int i = 0; i < n; i++){
        int randomNum = distribution(gen);
        randomVector.push_back(randomNum);
    }

    return randomVector;
}

int kLargest(vector<int> nums, int k){
    int mi = INT_MAX, ma = INT_MIN;
    int n = nums.size();
    unordered_map<int, int> u;

    if(n == 1) return nums[0];
    mi = min(nums[0], nums[1]);
    ma = max(nums[0], nums[1]);

    for(int i = 0; i < n; i++){
        int a = nums[i];

        u[a]++;
        mi = min(mi, a);
        ma = max(ma, a);
    } 

    if(k == n) return mi;

    for(int i = mi; i <= ma; i++){
        while(u[i]){
            n--;
            u[i]--;
            if(n == k - 1) return i;
        }
    }   

    return nums[0]; 
}

void Display(vector<int>& Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout<<endl;
}


int main(){
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    Display(nums);
    cout << "The kth largest element of the array is " << kLargest(nums, k) << "." << endl;

    vector<int> Random = GenerateRandom(10000);
    int kRandom = 515;

    Display(Random);
    cout << "The kth largest element of the array is " << kLargest(Random, kRandom) << "." << endl;

    return 0;
}
