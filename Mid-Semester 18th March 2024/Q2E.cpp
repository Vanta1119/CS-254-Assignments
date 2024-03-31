// 220001078

#include <bits/stdc++.h>

using namespace std;

int m1 = 150, m2 = 6, m3 = 7;

int Square(int n){
    if(n <= m1){
        return n*n;
    }

    return -n*n;
}

long double Exponential(int n){
    long double e = 2.718281828459045;
    if(n <= m2){
        return pow(e, n);
    }
    
    return -pow(e,n);
}

int Linear(int n){
    if(n <= m3){
        return n;
    }

    return -n;
}

long double fun(int n){
    long double e = 2.718281828459045;
    if(n <= m2){
        return pow(e, n);
    }
    
    return -pow(e,n);
}

int Better(int left, int right){
    int middle = left + (right-left)/2;
    
    if(right - left < 2){
        if(fun(left) > fun(right)){
            return left;
        }
        
        return right;
    }
    if(fun(middle) > fun(middle+1)){
        return Better(left, middle);
    }
    if(fun(middle+1) > fun(middle)){
        return Better(middle+1, right);
    }

    return middle;
}

void Display(vector<int>& Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout << endl;
}

int main() {
    // Space: O(1);

    int left = 0, right = 100000;

    // Time Better: O(log(right - left));
    cout << Better(left, right) << endl;

    return 0;
}
