#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (!k)
            return nums;

        int n = nums.size();
        vector<int> avgs(n, -1);
        
        if (2*k > n)
            return avgs;

        int l = 0, mid = k, r = 2*k;
        k = 2*k + 1;
        long long sum = 0;
        for (int i = 0; i < r; ++i)
            sum += nums[i];
        
        while (r < n) {
            sum += nums[r++];
            avgs[mid++] = sum / k; 
            sum -= nums[l++];
        }

        return avgs;
    }
};