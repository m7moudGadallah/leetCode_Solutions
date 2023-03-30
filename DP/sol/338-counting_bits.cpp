/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0;

        for (int i = 1; i <= n; i++) {
            ans[i] = (i&1) + ans[i>>1];
        }

        return ans;
    }
};