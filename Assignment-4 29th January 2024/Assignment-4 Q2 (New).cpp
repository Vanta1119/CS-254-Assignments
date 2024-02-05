#include <bits/stdc++.h>

using namespace std;

vector<int> GenerateSorted(int n){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distribution(-1000, 1000);

    vector<int> randomVector;

    int start = distribution(gen), jump = abs(distribution(gen)), iterations = n;

    for(int i = start; i <= start + jump*iterations; i += jump){
        randomVector.push_back(i);
    }

    return randomVector;
}

double findMedian(vector<int> &nums1, vector<int> &nums2) {
    int n1 = nums1.size(), n2 = nums2.size();

    if(n1 > n2) return findMedian(nums2, nums1);
    
    int n = n1 + n2;
    int left = (n + 1)/2;
    int low = 0, high = n1;
    
    while(low <= high){
        int mid1 = (low + high)/2;
        int mid2 = left - mid1;
        
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        
        if(mid1 < n1) r1 = nums1[mid1];
        if(mid2 < n2) r2 = nums2[mid2];
        if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
        
        if(l1 <= r2 && l2 <= r1){
            if(n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2)))/2;
        }
        else if(l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    
    return 80085.42069;
}

void Display(vector<int>& Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout << endl;
}

int main(){
    vector<int> nums1 = {1, 3}, nums2 = {2};

    Display(nums1);
    Display(nums2);

    cout << "The Mediam of nums1 and nums2 is: " << findMedian(nums1, nums2) << endl;


    vector<int> RandomA = GenerateSorted(12), RandomB = GenerateSorted(7);

    Display(RandomA);
    Display(RandomB);

    cout << "The Mediam of RandomA and RandomB in the Odd Sum Case is: " << findMedian(RandomA, RandomB) << endl;

    vector<int> RandomC = GenerateSorted(13), RandomD = GenerateSorted(7);

    Display(RandomC);
    Display(RandomD);

    cout << "The Mediam of RandomA and RandomB in the Even Sum Case is: " << findMedian(RandomC, RandomD) << endl;

    return 0;
}
