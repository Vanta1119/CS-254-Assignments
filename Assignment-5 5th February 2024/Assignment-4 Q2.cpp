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

double findMedian(vector<int> A, vector<int> B){
    unordered_map<int, int> u;
    int mi = A[0], ma = A[0];

    for(int i: A){
        u[i]++;
        mi = min(mi, i);
        ma = max(ma, i);
    }
    for(int i: B){
        u[i]++;
        mi = min(mi, i);
        ma = max(ma, i);
    }

    int mid = A.size() + B.size(); 

    if(mid % 2 == 0){
        mid /= 2;

        for(int i = mi; i <= ma; i++){
            while(u[i]){
                if(mid == 0) return i;
                u[i]--;
                mid--;
            }
        }
    }
    else{
        mid /= 2;

        int mid1 = mid, mid2 = mid + 1;
        double ans = 0;

        for(int i = mi; i <= ma; i++){
            while(u[i]){
                if(mid1 == 0) ans += i;
                if(mid2 == 0) ans += i;
                u[i]--;
                mid1--;
                mid2--;
            }
        }

        return ans / 2;
    }

    return 0;
}

void Display(vector<int>& Array){
    for(int i = 0; i < Array.size(); i++){
        cout << Array[i] << " ";
    }

    cout<<endl;
}

int main(){
    vector<int> nums1 = {1, 3}, nums2 = {2};

    Display(nums1);
    Display(nums2);

    cout << "The Mediam of nums1 and nums2 is: " << findMedian(nums1, nums2) << endl;


    vector<int> RandomA = GenerateSorted(12), RandomB = GenerateSorted(7);

    Display(RandomA);
    Display(RandomB);

    cout << "The Mediam of RandomA and RandomB is: " << findMedian(RandomA, RandomB) << endl;

    return 0;
}
