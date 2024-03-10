#include<bits/stdc++.h>

using namespace std;

vector<int> GenerateRandom(int n){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(1, 10000000);

    vector<int> randomVector;

    for(int i = 0; i < n; i++){
        int randomNum = distribution(gen);
        randomVector.push_back(randomNum);
    }

    return randomVector;
}

int LargestSum(vector<int> vec){
    int n = vec.size();

    if(n < 3){
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return vec[0] + vec[1];
    }

    int max1 = max(vec[0], vec[1]), max2 = min(vec[0], vec[1]);

    for(int i = 2; i < n; i++){
        int num = vec[i];

        if(num >= max1){
            max2 = max1;
            max1 = num;
        }
        if(num > max2 && max1 > num){
            max2 = num;
        }
    }

    return max1 + max2;
}

int main(){
    vector<int> vec = {3, 1, 4, 6, 8, 2, 5};
    vector<int> million = GenerateRandom(1000000);

    cout << "Largest 2Sum for the First Vector = " << LargestSum(vec) << endl;
    cout << "Largest 2Sum for the Second Vector = " << LargestSum(million) << endl;
    
    return 0;
}
