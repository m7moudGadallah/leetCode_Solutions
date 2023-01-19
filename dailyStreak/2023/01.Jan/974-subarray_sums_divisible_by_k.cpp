/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/**
 * Approach:
 *      how we know number is divisible by k?
 *           - by getting reminder of it if it equal to 0 so it's divisible (number = divisor * quoitent + reminder)
 *      so if we get prefixsum and get mod of it if this mod repeated again it means that we have a cycles `means --> (mod + m * k) i.e we have subarray their summation is divisible by k`
 * 
 *      so one we will git prefixsum of each element on array and get mod of it `mod = (((mod + x) % k) + k) %k` here we add k beacuase some times reminder will be negative so we avoid it by adding k
 *      
 *      now if this mod repeated it means between this modes we have an subarray it's sum divisible by k
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(map.size())
 */

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0, mod = 0;

        unordered_map<int, int> modFreq{{0, 1}};    //if we have element divisible by zero so we handle it by inital zero with 1

        for (auto &x : nums) {
            mod = (((mod + x) % k) + k) %k;
            ans += modFreq[mod];
            ++modFreq[mod];
        }

        return ans;
    }
};