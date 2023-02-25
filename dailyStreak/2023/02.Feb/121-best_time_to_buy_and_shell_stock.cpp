/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0, r = 0, mx_profit = 0;

        while (r < n) {
            if (prices[r] > prices[l])
                mx_profit = max(mx_profit, prices[r]-prices[l]);
            else
                l = r;
            ++r;
        }

        return mx_profit;
    }
};