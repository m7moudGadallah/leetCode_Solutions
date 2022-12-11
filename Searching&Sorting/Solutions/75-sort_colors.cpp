#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = (int) nums.size();

        if (n <= 1)
            return;

        int l{0}, r{n - 1}, curr{0};

        while (curr <= r)
        {
            if (nums[curr] == 0)
                swap(nums[curr], nums[l]), ++l;
            else if (nums[curr] == 2)
                swap(nums[curr], nums[r]), --r, --curr;

            ++curr;
        }
    }
};