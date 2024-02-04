#include <bits/stdc++.h> 

using namespace std; 

int max(int a, int b) return (a > b) ? a : b;

int knapSack(int W, int wt[], int val[], int n){ 
    if(n == 0 || W == 0) return 0; 

    if(wt[n - 1] > W) return knapSack(W, wt, val, n - 1); 
    else return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1)); 
} 

int main(){ 
    ifstream inputFile("input2.txt");
    ofstream outputFile("output2.txt");

    if(!inputFile.is_open() || !outputFile.is_open()){
    	cout << "Error opening files!" << endl;
	return 1;
    }

    int val[100], wt[100];
    int W, n;

    inputFile >> n;
    inputFile >> W;

    for(int i = 0; i < n; i++){
	inputFile >> val[i];
    }

    for (int i = 0; i < n; i++){
	inputFile >> wt[i];
    }

    outputFile << knapSack(W, wt, val, n) << endl;

    inputFile.close();
    outputFile.close();
    
    return 0; 
}
