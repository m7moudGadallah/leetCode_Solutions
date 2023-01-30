/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

// Intuition
//   we need to memorize each Tribonacci we get it

// Approach
//  Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
//  so now we see it's a problem we can calculate it from another sub problem so we can apply recursion and memoize each calculation
// Complexity
//      Time complexity: O(n)
//      Space complexity: O(n)

class Solution {
private:
    int dp[38];
public:
    Solution() {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i < 38; ++i)    dp[i] = -1;
    }
    int tribonacci(int n) {
        if (~dp[n])     return dp[n];
        return dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};