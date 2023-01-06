/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;


// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n, mid = 0, ans = -1;

        while (l <= r) {
            mid = l + ((r-l)>>1);

            if (isBadVersion(mid))
                ans = mid, r = mid - 1;
            else
                l = mid + 1;
        }

        return ans;
    }
};
