/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/*
    # Intuition
    what the range of numbers that a, b will be in [0, sqrt(c)] we estimate it with some mathematics

    # Approach
    so we will use `2 pointers` `l = 0` & `r = sqrt(c)` and iterate and calculate equation output `eq = l*l + r*r` if we found that `eq = c` then we get them and return true and if `eq > c` so we need to minimize ouput so we `--r` make right to go back finally if `eq < c` so we need to maximize output so we `++l` make left to go forward 

    # Complexity
    - Time complexity:
    O(N)

    - Space complexity:
    O(1)
*/

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = sqrt(c);

        while (l <= r) {
            long long eq = l*l + r*r;
            if (eq == c) return true;
            else if (eq > c)   --r;
            else ++l;
        }

        return false;
    }
};