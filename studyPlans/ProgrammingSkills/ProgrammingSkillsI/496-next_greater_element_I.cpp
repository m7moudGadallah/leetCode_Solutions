#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = (int) nums2.size();

        unordered_map<int, int> mp;

        stack<int> stk;

        for (int i = n - 1; i >= 0; --i)
        {
            while (!stk.empty() and stk.top() <= nums2[i])
                stk.pop();
            

            if (stk.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = stk.top();
            
            stk.push(nums2[i]);
        }

        vector<int> ans;

        for (const auto &x : nums1)
            ans.emplace_back(mp[x]);
        

        return ans;
    }
};