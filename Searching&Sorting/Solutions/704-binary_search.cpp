#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l {0}, r{(int) nums.size() - 1}, mid{0}, ans{0};

        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (nums[mid] <= target)
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }

        return (nums[ans] == target) ? ans : -1;
    }
};