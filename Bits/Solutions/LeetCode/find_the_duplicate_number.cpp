#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (auto &x : nums) {
            if (st.count(x))
                return x;
            
            st.insert(x);
        }

        return 0;
    }
};