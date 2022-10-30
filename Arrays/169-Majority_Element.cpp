#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        
        for (auto x : nums)
                mp[x]++;
        
        int mx = mp.begin()->first;
        
        for (auto x : mp)
            if (x.second > mp[mx])
                    mx = x.first;
        
        return mx;
    }
};