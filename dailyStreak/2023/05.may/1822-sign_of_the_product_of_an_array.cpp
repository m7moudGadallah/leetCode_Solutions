/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int signFunc(int num) {
        if (!num)
            return (0);
        return (num < 0) ? -1 : 1;
    }
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;

        for (auto &num : nums) {
            sign *= signFunc(num);

            if (!sign)
                return (0);
        }

        return sign;
    }
};