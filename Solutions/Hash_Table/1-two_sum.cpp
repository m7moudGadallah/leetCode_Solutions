#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = (int) nums.size();

        unordered_map<int, pair<int, int>> mp;      //map of (elements of nums, (frequency, last_postion))

        for (int i = 0; i < n; ++i)
            mp[nums[i]].first++, mp[nums[i]].second = max(mp[nums[i]].second, i);
        
        for (int i = 0; i < n; ++i)
        {
            int diff {target - nums[i]};         //get difference between current nums and target
            
            /*
                now we check if difference is equal to current item of nums
                so if this item frequency more than one (correct answer)
                otherwise (wrong answer)
            */
            if (diff == nums[i])
            {
                if (mp[nums[i]].first > 1)
                    return {i, mp[diff].second};
                else
                    continue;
            }
            else if (mp.count(diff))            //check if diff in map or not
                return {i, mp[diff].second};
        }

        return {0, 0};
    }
};