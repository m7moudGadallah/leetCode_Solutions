#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = (int) nums2.size();

        unordered_map<int, int> mp;                 //map of (nums2 element, next greater of it)

        stack<int> stk;                             //contains next greater elements fo current element

        for (int i = n - 1; i >= 0; --i)
        {
            while (!stk.empty() and stk.top() <= nums2[i])      //check if top is <= current element so we pop it
                stk.pop();
            

            if (stk.empty())            //if stack is empty so there is no elements is greater than this element
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