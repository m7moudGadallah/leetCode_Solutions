/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid = 0;

        while (l <= r) {
            mid = l + ((r-l)>>1);

            if (nums[mid] == target)     return mid;

            //left portion
            if (nums[l] <= nums[mid]) {
                if (target > nums[mid] or target < nums[l])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else {      //right portion
                if (target < nums[mid] or target > nums[r])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }

        return  -1;
    }
};
