/**
 *  @author Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();

        if (n > m)
            return false;
        
        if (!n)
            return  true;

        for (int i = 0; i < m; i++) {
            if (!flowerbed[i]) {
                bool emptyLeft = (!i or !flowerbed[i-1]),
                    emptyRight = (i == m-1 or !flowerbed[i+1]);
                
                if (emptyLeft and emptyRight)
                    flowerbed[i] = 1, --n;
            }

            if (!n)
                return true;
        }

        return false;
    }
};