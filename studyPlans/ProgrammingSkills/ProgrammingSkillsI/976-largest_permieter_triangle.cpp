#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
   inline bool valid(int &a, int &b, int &c) {
        return (a < b + c);
    }
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.rbegin(), nums.rend());

        for (int i = 0, e = n - 2; i < e; ++i)
            if (valid(nums[i], nums[i+1], nums[i+2]))
                return nums[i] + nums[i+1] + nums[i+2];
        
        return 0;
    }
};
