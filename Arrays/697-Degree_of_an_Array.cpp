#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct ele
    {
        int freq;
        int s;
        int e;

        ele(): freq(0), s(0), e(0){}
    };
public:
    int getwidth(ele &x)
    {
        return x.e - x.s + 1; 
    }

    int findShortestSubArray(vector<int>& nums) {
        map<int, ele> mp;

        for (int i = 0; i < (int) nums.size(); ++i)
        {
            if (!mp.count(nums[i]))
                mp[nums[i]].s = i;

            mp[nums[i]].freq++, mp[nums[i]].e = i;
        }

        int mx = 0, mn = 1e9;

        for (auto x : mp)
        {
            if (x.second.freq > mx)
            {
                mx = x.second.freq;
                mn = getwidth(x.second);
            }
            else if (x.second.freq == mx)
                mn = min(mn, getwidth(x.second));
        }

        return mn;
    }
};