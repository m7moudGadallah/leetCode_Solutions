#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = (int) nums.size();

        if (!n)
            return  {-1, -1};

        int l {0}, r{n - 1}, mid{0}, f_indx{-1};

        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (nums[mid] >= target)
                f_indx = mid, r = mid - 1;
            else
                l = mid + 1;
        }

        if (f_indx != -1 and nums[f_indx] == target)
        {
            int s_indx = f_indx + 1;

            while (s_indx < n)
            {
                if (nums[s_indx] == target)
                    ++s_indx;
                else
                    break;
            }

            if (s_indx >= n or nums[s_indx] != target)
                --s_indx;

            return {f_indx, s_indx};
        }

        return {-1, -1};
    }
};