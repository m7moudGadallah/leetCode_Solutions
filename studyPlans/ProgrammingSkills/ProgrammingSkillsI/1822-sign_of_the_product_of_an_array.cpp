#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign{1};   
        for (auto &x : nums) {
            if (!x)
                return 0;
            
            sign *= (x < 0) ? -1 : 1;
        }

        return sign;
    }
};
