#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k < 2)
            return 0;

        int len = nums.size(), p{0}, ans{0}, tot{1};

        for (int i = 0; i < len; ++i) {
            tot *= nums[i];

            while (tot >= k)
                tot /= nums[p++];
            
            ans += i-p + 1;
        }

        return ans;
    }
};