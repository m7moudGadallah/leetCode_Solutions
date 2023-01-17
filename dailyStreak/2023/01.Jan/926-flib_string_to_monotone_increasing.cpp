/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cntOnes = 0, cntFlibs = 0;

        for (auto &x : s) {
            if (x == '1')       ++cntOnes;
            else    cntFlibs = min(++cntFlibs, cntOnes);
        }

        return cntFlibs;
    }
};