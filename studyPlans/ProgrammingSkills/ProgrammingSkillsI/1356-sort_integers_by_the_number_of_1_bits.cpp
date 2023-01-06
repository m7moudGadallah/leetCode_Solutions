/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;


class Solution {
private:
    int count1Bits(int n) {
        if (!n)     return 0;
        return (n&1) + count1Bits(n>>1);
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int x, int y){
            int cntx = count1Bits(x), cnty = count1Bits(y);
            return (cntx == cnty) ? x<y : cntx<cnty;
        });

        return arr;
    }
};