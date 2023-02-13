/**
 *  Author: Mahmoud Gadallah
 *  LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();

        int idx = 1;
        while (idx < n and nums[idx] == nums[idx-1])        ++idx;

        if (idx >= n)       return true;

        bool flag = (nums[idx] > nums[idx-1]);

        while (idx < n) {
            if (nums[idx] != nums[idx-1] and (flag != (nums[idx] > nums[idx-1])))
                return false;
            ++idx;
        }

        return true;
    }
};