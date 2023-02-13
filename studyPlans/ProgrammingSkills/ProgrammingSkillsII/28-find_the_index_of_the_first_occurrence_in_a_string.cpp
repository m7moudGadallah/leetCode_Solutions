/**
 *  Author: Mahmoud Gadallah
 *  LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();

        if (m > n)
            return -1;

        int ans{-1}, p{0};

        for (int i = 0; i < n; ++i) {
            ans = i, p = i;
            
            for (int j = 0; j < m; ++j) {
                if (needle[j] != haystack[p++]) {
                    ans = -1;
                    break;
                }
            }

            if (ans != -1)
                return ans;
        }

        return -1;
    }
};