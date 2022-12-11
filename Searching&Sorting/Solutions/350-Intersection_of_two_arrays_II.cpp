#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;

        for (const auto &x : nums1)
            freq[x]++;

        vector<int> ans;

        for (const auto &x : nums2)
            if (freq.count(x) and freq[x])
                ans.emplace_back(x), --freq[x];
            
        ans.shrink_to_fit();

        return ans;
    }
};