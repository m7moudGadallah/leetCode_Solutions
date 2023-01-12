/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int p1 = 0, p2 = 0, mx = 0;

        while (p1 < n and p2 < m) {
            if (nums1[p1] > nums2[p2]) ++p1;
            else
                mx = max(mx, p2 - p1), ++p2;
        }

        return mx;
    }
};