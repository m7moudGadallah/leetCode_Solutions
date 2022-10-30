#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int n = (int)nums.size();
        set<int> st;
        vector<int> ans;
        
        int cnt = 1;
        
        for (auto x : nums)
            st.insert(x);
        
        auto it = st.begin();

        while (it != st.end())
        {
            while (*it != cnt)
                ans.emplace_back(cnt++);

            ++cnt, ++it;
        }

        while (cnt <= n)
            ans.emplace_back(cnt++);
        
        return ans;
    }
};