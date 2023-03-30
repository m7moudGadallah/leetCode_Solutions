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
        vector<int> buy(n);

        buy[0] = prices[0];

        for (int i = 1; i < n; i++) {
            buy[i] = min(buy[i-1], prices[i]);
        }

        int mx = 0;

        for (int i = 1; i < n; i++) {
            mx = max(mx, prices[i] - buy[i-1]);
        }

        return mx;
    }
};