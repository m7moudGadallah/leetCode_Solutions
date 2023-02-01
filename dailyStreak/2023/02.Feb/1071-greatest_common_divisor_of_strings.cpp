/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isVaildDivisor(string quotient, string divisor) {
        int n = quotient.size(), m = divisor.size();

        for (int i = 0; i < n; i += m)
            if (quotient.substr(i, m) != divisor)   return false;
        
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        int m = min(str2.size(), str1.size());
        string currDiv = "", ans = "";


        for (int i = 0; i < m; ++i) {
            currDiv += str2[i];
            if (isVaildDivisor(str1, currDiv) and isVaildDivisor(str2, currDiv))
                ans = currDiv;
        }

        return ans;
    }
};