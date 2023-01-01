#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int slow = 0, fast = 0;


        for (; fast < n; fast++) {
            if (nums[fast])
                nums[slow++] = nums[fast];
        }

        while (slow < n)
            nums[slow++] = 0;

    }
};