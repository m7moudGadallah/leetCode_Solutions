#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size()-1, mid, ans;

        while (l <= r) {
            mid = l + ((r-l)>>1);
            
            if (!mid or arr[mid] > arr[mid-1])
                l = mid + 1, ans = mid;
            else
                r = mid - 1;
        }
        return ans;        
    }
};