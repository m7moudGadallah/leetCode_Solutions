#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        int n {(int) nums.size() / 2};

        unordered_map<int, int> mp;

        for (const auto &num : nums)
        {
            mp[num]++;

            if (mp[num] == n)
                return num;
        }
        
        return 0;
    }
};