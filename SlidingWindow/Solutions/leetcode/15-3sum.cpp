#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i) {
            if (i > 0 and nums[i] == nums[i - 1])
                continue;
            
            int l = i + 1, r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum > 0)
                    --r;
                else if (sum < 0)
                    ++l;
                else {
                    ans.emplace_back(vector<int>({nums[i], nums[l], nums[r]}));
                    ++l;

                    while (nums[l] == nums[l - 1] and l < r)
                        ++l;
                }
            }
        }

        return ans;
    }
};