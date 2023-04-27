/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int sumDigits(int num) {
        if (!num)       return (0);

        return ((num % 10) + sumDigits(num / 10));
    }
public:
    int addDigits(int num) {
        if (!(num / 10))       return (num);

        return addDigits(sumDigits(num));
    }
};