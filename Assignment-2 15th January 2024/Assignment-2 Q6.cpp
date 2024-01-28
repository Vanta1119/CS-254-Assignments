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

int Median(vector<int>& arr, int left, int middle, int right) {
    if ((arr[left] >= arr[middle] && arr[left] <= arr[right]) || 
        (arr[left] <= arr[middle] && arr[left] >= arr[right]))
        return left;
    else if ((arr[middle] >= arr[left] && arr[middle] <= arr[right]) || 
             (arr[middle] <= arr[left] && arr[middle] >= arr[right]))
        return middle;
    else
        return right;
}

int partition(vector<int>& arr, int left, int right) {
    int pivotIndex = Median(arr, left, left + (right - left) / 2, right);
    swap(arr[pivotIndex], arr[right]);

    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void Display(vector<int> Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout<<endl;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    vector<int> nums = {12, 11, 13, 5, 6, 7};
    vector<int> RandomA = GenerateRandom(500), RandomB = GenerateRandom(100000);

    quickSort(nums, 0, nums.size() - 1);

    Display(nums);
    cout << "Sorted array: ";
    Display(nums);

    Display(RandomA);
    quickSort(RandomA, 0, RandomA.size() - 1);
    Display(RandomA);

    cout << "Sorting RandomB!" << endl;
    quickSort(RandomB, 0, RandomB.size() - 1);
    cout << "Sorted RandomB!" << endl;

    return 0;
}
