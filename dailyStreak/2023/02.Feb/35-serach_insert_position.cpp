/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/**
 * @brief Problem Explanation
 * @link https://leetcode.com/problems/search-insert-position/solutions/3209371/simple-c-solution-beats-more-than-90/
 */


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, mid = 0, ans = -1;

        if (target <= nums.front())     return 0;
        if (target == nums.back())      return r;
        if (target > nums.back())       return r+1;

        while (l <= r) {
            mid = l + ((r-l)>>1);

            if (nums[mid] <= target)        ans = mid, l = mid + 1;
            else    r = mid - 1;
        }

        return (ans != -1 and nums[ans] == target) ?  ans : ans + 1;
    }
};