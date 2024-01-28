#include <bits/stdc++.h>
using namespace std;

void mergeInPlace(vector<int>& Array, int left, int middle, int right){
    int maximum = max(Array[middle], Array[right]) + 1;

    int i = left, j = middle + 1, k = left;
    while (i <= middle && j <= right && k <= right) {
        int element1 = Array[i] % maximum;
        int element2 = Array[j] % maximum;
        if (element1 <= element2) {
            Array[k] += (element1 * maximum);
            i++;
            k++;
        }
        else {
            Array[k] += (element2 * maximum);
            j++;
            k++;
        }
    }

    while (i <= middle) {
        int el = Array[i] % maximum;
        Array[k] += (el * maximum);
        i++;
        k++;
    }

    while (j <= right) {
        int el = Array[j] % maximum;
        Array[k] += (el * maximum);
        j++;
        k++;
    }

    for (int i = left; i <= right; i++)
        Array[i] /= maximum;
}

void mergeSort(vector<int>& Array, int left, int right){
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(Array, left, middle);
        mergeSort(Array, middle + 1, right);
        mergeInPlace(Array, left, middle, right);
    }
}

void Display(vector<int> Array){
    for(int i=0; i<Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout << endl;
}

int main(){
    vector<int> nums = {0, 2, 3, 12, 11, 13, 5, 6, 7, 23, 25, 28};
    int m = 3;

    Display(nums);

    mergeSort(nums, m, nums.size() - 1 - m);

    Display(nums);

    return 0;
}
