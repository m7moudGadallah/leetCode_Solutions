#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int sz = (int) nums.size();

        if (target < nums.front())
            return 0;
        
        if (target > nums.back())
            return sz;

        int l {0}, r{sz - 1}, mid{0}, ans{0};

        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (nums[mid] <= target)
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }

        return (nums[ans] == target) ? ans : ans + 1;
    }
};