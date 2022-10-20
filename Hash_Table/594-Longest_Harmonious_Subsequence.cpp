#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        
        map<int, int> freq;             //frequency map of nums elements

        for (const auto &num : nums)
            freq[num]++;

        
        auto it = freq.begin(), last = it;
        ++it;

        int mx{0};              //maximum length of harmonious subsequence

        while (it != freq.end())
        {
            if (it->first - last->first == 1)
                mx = max(it->second + last->second, mx);
            
            last = it;
            ++it;
        }

        return mx;
    }
};