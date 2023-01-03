#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, mx = INT_MIN;

        for (auto &x : nums) {
            sum += x;

            mx = max(sum, mx);

            if (sum < 0)        sum = 0;
        }

        return mx;
    }
};