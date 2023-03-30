/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        for (int i = 2; i < n; i++) {
            cost[i] += min(cost[i-1], cost[i-2]);
        }

        return min(cost[n-2], cost[n-1]);
    }
};