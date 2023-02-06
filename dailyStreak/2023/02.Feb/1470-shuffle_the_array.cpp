#include<bits/stdc++.h>

using namespace std;


// # Approach
// we need pointer to point at the begining of array `p1` and another pointer to point at `nth` element in the array `p2` then we need to create a vector `ans` and keep pushing back element at `p1` and element at `p2` and increment `p1` & `p2`

// # Complexity
// - Time complexity:
// O(n)

// - Space complexity:
// o(n^2)

/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int p1 = 0, p2 = n;
        vector<int> ans;

        while (p1 < n) {
            ans.emplace_back(nums[p1++]);
            ans.emplace_back(nums[p2++]);
        }

        return ans;
    }
};