#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        sort(nums.begin(), nums.end());

        //prefix summ of nums
        for (int i = 1; i < (int) nums.size(); ++i)
            nums[i] += nums[i - 1];
        
        vector<int> ans;

        //iterate over queries
        for (auto x : queries)
        {
            auto it = upper_bound(nums.begin(), nums.end(), x);

            if (it == nums.end())
                ans.emplace_back((int) nums.size());
            else
                ans.emplace_back(it - nums.begin());
        }

        return ans;
    }
};