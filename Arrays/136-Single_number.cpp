#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num{0};
        
        for (auto x : nums)
                num ^= x;
        
        return num;
    }
};