#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int indx{0}, n{(int) nums.size()}, sum{0};

        while (indx < n)
            sum += nums[indx], indx += 2;
        

        return sum;
    }
};