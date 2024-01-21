#include <bits/stdc++.h>

using namespace std;

vector<int> GenerateRandom(int n){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(1, 500);

    vector<int> randomVector;

    for(int i = 0; i < n; i++){
        int randomNum = distribution(gen);
        randomVector.push_back(randomNum);
    }

    return randomVector;
}

void Display(vector<int> Array){
    for(int i=0; i<Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout << endl;
}

void Median(vector<int> Array){  
    int n = Array.size();

    sort(Array.begin(), Array.end());

    cout << "Median: " << Array[n/2] << endl;
}

int main(){
    vector<int> toSort={53, 8, 2, 6, 89, 23, 6};
    vector<int> RandomA = GenerateRandom(500), RandomB = GenerateRandom(100000);

    Median(toSort);
    Display(toSort);

    Median(RandomA);
    Display(RandomA);

    Median(RandomB);

    return 0;
}