/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/**
 * @brief Problem Explanation
 * @link https://leetcode.com/problems/single-element-in-a-sorted-array/solutions/3215526/simple-c-solution-beats-more-than-96/
 */


class Solution {
private:
    vector<int> nums;
    inline bool correct(int mid) {
        if (mid&1) {        //check if mid is odd
            if (nums[mid] == nums[mid-1])
                return true;
        }
        else {
            if (mid < nums.size()-1 and nums[mid] == nums[mid+1])
                return true;
        }
        return false;
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        this->nums = nums;
        int l = 0, r = nums.size()-1, mid = 0, ans = -1;

        while (l <= r) {
            mid = l + ((r-l)>>1);

            if (correct(mid))
                l = mid + 1;
            else
                r = mid - 1, ans = mid;
        }

        return nums[ans];
    }
};