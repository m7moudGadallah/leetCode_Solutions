#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int tot_product = 1;
        
        int zeros{0};
        
        for (auto x : nums)
                if (x)
                    tot_product *= x;
                else
                    zeros++;
        
        int sz = (int)nums.size();
        
        vector<int> ans(sz);
        
        for (int i = 0; i < sz; ++i)
        {
            if (nums[i])
            {
                if (zeros)
                    ans[i] = 0;
                else
                    ans[i] = tot_product / nums[i];
            }
            else
            {
                if (zeros > 1)
                    ans[i] = 0;
                else
                    ans[i] = tot_product;
            }
        }
        
        return ans;
    }
};