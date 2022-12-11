#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size(), l{0}, r{0}, sum{0}, mn{INT_MAX};

        while (r < len) {
            sum += nums[r++];

            while (sum >= target) {
                mn = min(mn, r - l);
                sum -= nums[l++];
            }
        }

        return (mn == INT_MAX) ? 0 : mn;
    }
};