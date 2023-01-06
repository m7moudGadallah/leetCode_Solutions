/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0, r = 1, mn_l = 0, mx = 0;

        while (r < n) {
            if (prices[r] < prices[r - 1])
                l = r, mn_l = (prices[l] < prices[mn_l]) ? l : mn_l;
            
            int profit = max(prices[r] - prices[l], prices[r] - prices[mn_l]);
            mx = max(mx, profit);
            ++r;
        }

        return mx;
    }
};