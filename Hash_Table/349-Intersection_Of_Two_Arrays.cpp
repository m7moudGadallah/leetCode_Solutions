#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;

        for (const auto &x : nums1)
            st.emplace(x);
        
        vector<int> ans;

        for (const auto &x : nums2)
        {
            auto it = st.find(x);

            if (it == st.end())
                continue;
            
            ans.emplace_back(*it);
            st.erase(it);
        }

        return ans;
    }
};