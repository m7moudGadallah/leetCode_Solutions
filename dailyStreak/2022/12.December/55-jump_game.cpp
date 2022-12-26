#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1)
            return true;

        int p = n-1;

        for (int i = n-2; i >= 0; --i) {
            if (nums[i] + i >= p)
                p = i;
        }

        return !p;
    }
};