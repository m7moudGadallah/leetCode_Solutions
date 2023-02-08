/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, cnt = 0, n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            r = max(r, nums[i]+i);

            if (r >= n-1) return ++cnt;

            if (i == l) {
                l = r;
                ++cnt;
            }
        }

        return cnt;
    }
};