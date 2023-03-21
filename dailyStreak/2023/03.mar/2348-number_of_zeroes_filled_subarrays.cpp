/**
 *  @author Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

//tutorial: https://leetcode.com/problems/number-of-zero-filled-subarrays/solutions/3325544/c-solution-beats-more-than-91/
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long zeroes = 0,
            ans = 0;
        
        auto numOfSub = [](long long &sz) {
            return sz * (sz+1) / 2;
        };

        for (auto &x : nums) {
            if (!x)
                ++zeroes;
            else {
                ans += numOfSub(zeroes);
                zeroes = 0;
            }
        }

        if (zeroes)
            ans += numOfSub(zeroes);
        
        return ans;
    }
};