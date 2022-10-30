#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sval{1}, sum{1};
        
        for (auto x : nums)
        {
            sum += x;
            
            if (sum < 1)
                sval += abs(sum) + 1, sum = 1;
        }
        
        return sval;
    }
};