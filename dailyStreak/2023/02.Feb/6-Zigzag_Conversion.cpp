/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (n <= numRows or numRows == 1) {
            return s;
        }

        vector<string> pattern(numRows);
        int idx = 0, r = 0, dir = 1;

        while (idx < n) {
            pattern[r].push_back(s[idx]);
            r += dir;
            if (r == numRows)   r -= 2,dir = -1;
            if (r < 0)          r += 2, dir = 1;
            ++idx;
        }

        string ans;
        for (auto &x : pattern)
            ans += x;
        
        return ans;
    }
};