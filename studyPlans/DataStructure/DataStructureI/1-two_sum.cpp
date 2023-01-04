/*
    Author: Mahmoud Gadallah
    LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = (int) nums.size();

        unordered_map<int, pair<int, int>> mp;

        for (int i = 0; i < n; ++i)
            mp[nums[i]].first++, mp[nums[i]].second = max(mp[nums[i]].second, i);
        
        for (int i = 0; i < n; ++i)
        {
            int tmp {target - nums[i]};
            
            if (tmp == nums[i])
            {
                if (mp[nums[i]].first > 1)
                    return {i, mp[tmp].second};
                else
                    continue;
            }
            else if (mp.count(tmp))
                return {i, mp[tmp].second};
        }

        return {0, 0};
    }
};