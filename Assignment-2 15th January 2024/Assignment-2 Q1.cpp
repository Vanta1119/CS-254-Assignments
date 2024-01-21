#include <bits/stdc++.h>

using namespace std;

vector<int> GenerateSorted(int n, int start, int jump){
    vector<int> randomVector(n, 0);
    int iterator = 0;

    for(int i = start; i < start + jump * n; i = i + jump){
        randomVector[iterator] = i;
        iterator++;
    }

    return randomVector;
}

vector<int> Merge(vector<int> A, vector<int> B){  
    int m = A.size(), n = B.size();
    int a = 0, b = 0;

    vector<int> Merged;

    for(int i = 0; i < m + n; i++){
        if(a == m || A[a] >= B[b]){
            Merged.push_back(B[b]);
            b++;
        }
        else if(b == n || A[a] < B[b]){
            Merged.push_back(A[a]);
            a++;
        }
    }

    return Merged;
}

vector<int> Union(vector<int> A, vector<int> B){  
    int m = A.size(), n = B.size();
    int a = 0, b = 0;
    int prev = INT_MIN + 2052;

    vector<int> Union;

    while(a + b != m + n){
        if(a == m || A[a] >= B[b]){
            if(prev == B[b]){
                b++;
                continue;
            }

            prev = B[b];
            Union.push_back(B[b]);
            b++;
        }
        else if(b == n || A[a] < B[b]){
            if(prev == A[a]){
                a++;
                continue;
            }

            prev = A[a];
            Union.push_back(A[a]);
            a++;
        }
    }

    return Union;
}

vector<int> Intersection(vector<int> A, vector<int> B){  
    int m = A.size(), n = B.size();
    int a = 0, b = 0;

    vector<int> Intersection;

    while(a + b != m + n){
        if(a < m && b < n && A[a] == B[b]){
            Intersection.push_back(A[a]);
            a++;
            b++;
        }
        if(a == m || A[a] > B[b]){
            b++;
        }
        else if(b == n || A[a] < B[b]){
            a++;
        }
    }

    return Intersection;
}

void Display(vector<int> Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout<<endl;
}

int main(){
    vector<int> TestA = GenerateSorted(10, 30, 3), TestB = GenerateSorted(20, 22, 2);

    cout<<"Array TestA[]: ";
    Display(TestA);
    cout<<"Array TestB[]: ";
    Display(TestB);

    vector<int> TestC1 = Merge(TestA, TestB);
    cout<<"Array TestC1[]: ";
    Display(TestC1);


    vector<int> A = GenerateSorted(10000000, 30, 3), B = GenerateSorted(1000000, 22, 2);

    cout<<"Array A[]: ";
    // Display(A);
    cout<<"Array B[]: ";
    // Display(B);

    vector<int> C = Merge(A, B);
    cout<<"Array C[]: ";
    // Display(C);


    vector<int> TestC2 = Union(TestA, TestB);
    cout<< endl << "Array TestC2[]: ";
    Display(TestC2);


    vector<int> TestC3 = Intersection(TestA, TestB);
    cout<<"Array TestC3[]: ";
    Display(TestC3);

    return 0;
}