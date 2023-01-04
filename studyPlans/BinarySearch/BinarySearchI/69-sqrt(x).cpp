/*
    Author: Mahmoud Gadallah
    LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int l{0}, r{x}, mid{0}, ans{-1};

        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if ((long long)mid * mid <= x)
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }

        return ans;
    }
};