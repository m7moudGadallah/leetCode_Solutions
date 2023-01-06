/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;


class NumArray {
private:
    vector<int> arr;
    int n;
public:
    NumArray(vector<int>& nums) {
        this->arr = nums;
        this->n = nums.size();

        for (int i = 1; i < n; ++i)     //prefix sum
            arr[i] += arr[i-1];
    }
    
    int sumRange(int left, int right) {
        if (!left)
            return arr[right];
        
        return arr[right] - arr[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */