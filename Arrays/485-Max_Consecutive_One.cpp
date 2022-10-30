#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sz = (int) nums.size();
        
        int cnt{}, mx{0};
        
        for (auto x : nums)
        {
            if (x == 1)
                    ++cnt;
            else
                cnt = 0;
                
            mx = max(mx, cnt);
        }
        
        return mx;
    }
};