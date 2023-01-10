/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/*
# Intuition
what is the range that x will be in?
- min suitable `x` is 1 and max suitable `x` is `n` where`n` is `size of nums`
- so know we have serach space we can serach on it with using binary serach 

# Approach
Ok know we know what is the search space of `x` but how to know if this `x` is suitable or not ?
so we will count number of elements which is greater than or equal x we will called it `cnt` and if their `cnt` is equal to `x` then we found it
so to make counting operation much faster we will **sort** nums and then serach for the first num which is greater than or equal to `x` we will called it `pos` now `cnt = n - pos`

# Complexity
- Time complexity:
`O(n log(n))`
sorting with `O(nlog(n))`
seraching with `O((log(n))^2)` beacuse seraching on answer and inside it finding number of elements greater than x

so total complexity will be `O(n log(n))`

- Space complexity:
O(1)
*/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 1, r = n, mid = 0;

        while (l <= r) {
            mid = l + ((r-l)>>1);

            auto lb = lower_bound(nums.begin(), nums.end(), mid);   //binary serach for first position that greater than or equal to mid

            int cnt = n - (lb-nums.begin());        //number of element greater than or equal to mid

            if (cnt == mid) return mid;
            else if (cnt > mid) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }
};
