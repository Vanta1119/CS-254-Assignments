// 220001078

#include <bits/stdc++.h>

using namespace std;

int Better(vector<int> &v, int left, int right){
    int middle = left + (right-left)/2;
    
    if(right - left < 2){
        return max(v[left], v[right]);
    }
    if(v[middle] > v[middle+1]){
        return Better(v, left, middle);
    }
    if(v[middle+1] > v[middle]){
        return Better(v, middle+1, right);
    }

    return v[middle];
}

void Display(vector<int>& Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout << endl;
}

int main() {
    // Space: O(1);
    
    // vector<int> Arr = {77, -135};  //Edge Case Testing
    // vector<int> Arr = {77, 135};  //Edge Case Testing
    // vector<int> Arr = {77};  //Edge Case Testing
    // vector<int> Arr = {1, 4, 7, 9, 12, 3, 2, 1, -1, -2, -3, -5};  //Case Testing
    
    int n;
    cin >> n;
    
    vector<int> Arr(n);

    for(int i = 0; i < n; i++){
        cin >> Arr[i];
    }

    // Time Better: O(log(n));
    cout << Better(Arr, 0, Arr.size()-1) << endl;

    return 0;
}
