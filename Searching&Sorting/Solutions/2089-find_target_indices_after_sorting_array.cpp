#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int sz{(int) nums.size()};

        int l{0}, r{sz - 1}, mid{0}, pos{-1};
        vector<int> ans;

        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (nums[mid] >= target)
                pos = mid, r = mid - 1;
            else
                l = mid + 1;
        }

        while (pos > -1 and pos < sz and nums[pos] == target)
            ans.emplace_back(pos++);
        
        return ans;
    }
};