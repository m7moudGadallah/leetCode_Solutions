#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        if (!k)
            return true;

        int n {(int) nums.size()};

        map<int, int> freq;       //frequency map

        int l{0}, r{1};             //initalize left and right of winodw
        freq[nums[0]]++;

        while (r < n)
        {
            if (r - l > k)          // if window size become graeater than k then we move l forward
            {
                (freq[nums[l]] > 1) ? freq[nums[l]]-- : freq.erase(nums[l]);
                ++l;
            }
            
            if (freq.count(nums[r]))
                return true;
            else
                freq[nums[r]]++;
            
            ++r;
        }
        
        return false;
    }
};