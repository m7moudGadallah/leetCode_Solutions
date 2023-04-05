/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
bool isValidMax(vector<long long> &prefixSum, int mx) {
    int n = prefixSum.size();

    if (prefixSum.front() > mx)     //we can't modify first element
        return false;
    
    //bool flag to check if we can have this mx in arrray after modified or not
    bool haveMx = false;

    for (int i = 1; i < n; ++i) {
        if (prefixSum[i] > (long long)mx * (i + 1))    //that means array still contains numbers greater than mx
            return false;
        
        if (!haveMx and prefixSum[i] > mx)
            haveMx = true;
    }

    return haveMx;
}
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size(),
            l = 0,
            r = *max_element(nums.begin(), nums.end()),
            mid = 0,
            ans = r;
        
        //generate prefix sum
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i)
            prefixSum[i] = nums[i] + prefixSum[i-1];
        
        //binary sreach on answer in serach space (0 --> max_element in array)
        while (l <= r) {
            mid = l + ((r - l) >> 1);

            if (isValidMax(prefixSum, mid))
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }

        return ans;
    }
};