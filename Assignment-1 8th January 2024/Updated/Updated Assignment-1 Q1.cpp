#include <bits/stdc++.h>

using namespace std;

pair<int, int> findMaxSumPair(const vector<int>& arr) {
    int n = arr.size();
    if(n < 2){
        return make_pair(-1, -1);
    }

    int max1 = max(arr[0], arr[1]);
    int max2 = min(arr[0], arr[1]);
    
    for(int i = 2; i < n; ++i){
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }
    }

    return make_pair(max1, max2);
}

int main(){
    ifstream inputFile("input1.txt");
    ofstream outputFile("output1.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> arr[i];
    }

    pair<int, int> result = findMaxSumPair(arr);

    outputFile << "Maximum Sum Pair: " << result.first << " + " << result.second << " = " << result.first + result.second << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
