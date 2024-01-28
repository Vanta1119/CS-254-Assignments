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

void Swap(vector<int> &Array, int left, int right){
    int c = Array[left] + Array[right]; 

    Array[left] = c - Array[left];
    Array[right] = c - Array[left];
}

void Merge(vector<int> &Array, int left, int middle, int right){  
    int len1 = middle - left + 1, len2 = right - middle;
    int it1 = left, it2 = middle;

    for(int i = 0; i < len1; i++){
        if(Array[it1 - i] > Array[it2 + i]){
            for(int j = i; j < it1; j++){
                Swap(Array, it1 + j, it2);
            }
        }
    }
}

vector<int> MergeSort(vector<int> &Array, int left, int right){
    if(left < right){
        int middle = left + (right-left)/2; 

        MergeSort(Array, left, middle);
        MergeSort(Array, middle+1, right);

        Merge(Array, left, middle, right);
    }

    return Array;
}

int main(){
    vector<int> toSort={53, 8, 2, 6, 89, 23, 6};
    vector<int> RandomA = GenerateRandom(500), RandomB = GenerateRandom(100000);

    cout<<"Unsorted Array: ";

    Display(toSort);

    MergeSort(toSort, 0, toSort.size()-1);

    cout<<"Sorted Array: ";
    
    Display(toSort);

    cout<<"Unsorted Array: ";

    // Display(RandomA);

    // MergeSort(RandomA, 0, 499);

    cout<<"Sorted Array: ";
    
    // Display(RandomA);

    cout<<"Starting sorting on RandomB."<<endl;

    // MergeSort(RandomB, 0, 99999);

    cout<<"Successfully sorted RandomB."<<endl;

    return 0;
}