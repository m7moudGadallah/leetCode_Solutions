#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = *max_element(nums.begin(), nums.end());

        if (sum < 0)
            return sum;
        
        int curr_sum{0};

        for (auto x : nums)
        {
            curr_sum += x;

            if (curr_sum < 0)
                curr_sum = 0;

            sum = max(sum, curr_sum);
        }

        return sum;
    }
};