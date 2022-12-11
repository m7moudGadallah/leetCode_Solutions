#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = (int) nums.size();

        if (n == 1)
            return 0;
        
        int l{0}, r{n - 1}, mid{0}, ans{-1};

        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (mid != n - 1 and nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                ans = mid, r = mid - 1;
        }

        return ans;
    }
};