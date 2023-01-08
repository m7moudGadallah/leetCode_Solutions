/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/**
 * Time Complexity: O(Nlog(N))
*/

class Solution {
private:
    vector<int> nums;
    int BinSerach(int l, int r, int target) {
        int mid = 0;

        while (l <= r) {
            mid = l + ((r-l)>>1);

            if (nums[mid] == target)        return mid;
            else if (nums[mid] > target)    r = mid - 1;
            else    l = mid + 1;
        }

        return -1;
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        this->nums = numbers;

        for (int i = 0, ei = n -1; i < n; ++i) {
            int found = BinSerach(i+1, n-1, target-numbers[i]);
            if (found != -1)
                return {++i, ++found};
        }

        return {0, 0};
    }
};