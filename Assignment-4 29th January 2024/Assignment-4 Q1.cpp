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

int Inversions(vector<int> A){
    int n = A.size();

    int ans = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(A[i] > A[j]) ans++;
        }
    }

    return ans;
}

void Display(vector<int>& Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout << endl;
}

int main(){
    vector<int> nums = {3, 2, 1};
    cout << "The Array has a total of " << Inversions(nums) << " inversions." << endl;

    vector<int> Random = GenerateRandom(10);
    Display(Random);
    cout << "The Array has a total of " << Inversions(Random) << " inversions." << endl;

    return 0;
}
