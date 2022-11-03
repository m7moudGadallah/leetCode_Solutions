#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mn{INT_MAX}, mx{INT_MIN};

        for (const auto &x : nums)
            mn = min(mn, x), mx = max(mx, x);
        

        int diff = mx - mn;

        if (!diff or diff <= 2 * k)
            return 0;
        
        return diff - 2 * k;
    }
};