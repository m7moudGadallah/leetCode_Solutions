#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int p = 0, sum = 0, mx = 0;
        unordered_map<int, int> found;

        for (int i = 0; i < n ; ++i) {
            if (found.count(nums[i])) {
                int end = found[nums[i]];
                while (p <= end) {
                    sum -= nums[p];
                    found.erase(nums[p++]);
                }
            }
            
            sum += nums[i];
            found[nums[i]] = i;
            mx = max(mx, sum);
        }

        return mx;
    }
};
