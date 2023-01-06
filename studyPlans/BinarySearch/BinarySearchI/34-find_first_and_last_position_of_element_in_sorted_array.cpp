/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n)
            return {-1, -1};
        
        int l = 0, r = n-1, mid = 0, sIdx = -1;
        while (l <= r) {
            mid = l + ((r-l)>>1);

            if (nums[mid] >= target)
                sIdx = mid, r = mid - 1;
            else
                l = mid + 1;
        }

        if (sIdx == -1 or nums[sIdx] != target)
            return {-1, -1};
        
        int eIdx = sIdx+1;

        while (eIdx < n and nums[eIdx] == target)
            ++eIdx;
        
        return {sIdx, --eIdx};
    }
};