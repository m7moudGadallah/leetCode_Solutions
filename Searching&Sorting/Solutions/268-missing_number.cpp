#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans{0}, n{(int) nums.size()};

        for (int i = 0; i < n; ++i)
            ans ^= i ^ nums[i];
        
        ans ^=  n;

        return ans;
    }
};