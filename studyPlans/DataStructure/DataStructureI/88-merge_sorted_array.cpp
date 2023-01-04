/*
    Author: Mahmoud Gadallah
    LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!n)     return;

        int idx = n+m - 1;
        --m, --n;

        while (m >= 0 and n >= 0) {
            if (nums1[m] > nums2[n])
                nums1[idx--] = nums1[m--];
            else
                nums1[idx--] = nums2[n--];
        }

        while (n >= 0)
            nums1[idx--] = nums2[n--];
    }
};