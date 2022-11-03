#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = (int) nums.size();

        deque<int> dq;

        for (int i = 0; i < k; ++i)
        {
            while (!dq.empty() and nums[i] >= nums[dq.back()])
                dq.pop_back();
            
            dq.emplace_back(i);
        }

        vector<int> ans;

        for (int i = k; i < n; ++i)
        {
            ans.emplace_back(nums[dq.front()]);

            while (!dq.empty() and dq.front() <= i - k)
                dq.pop_front();

            while (!dq.empty() and nums[i] >= nums[dq.back()])
                dq.pop_back();
            
            dq.emplace_back(i);
        }
        
        ans.emplace_back(nums[dq.front()]);

        ans.shrink_to_fit();

        return ans;
    }
};