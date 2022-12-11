#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        map<int, int> freq;

        for (const auto &x : nums)
            freq[x]++;

        auto it = freq.begin();
        int tmp = it->second;
        it->second = 0;
        ++it;

        while (it != freq.end())
        {
            swap(it->second, tmp);
            tmp += it->second;
            ++it;
        }

        vector<int> ans;

        for (const auto &x : nums)
            ans.emplace_back(freq[x]);
        
        ans.shrink_to_fit();

        return ans;
    }
};