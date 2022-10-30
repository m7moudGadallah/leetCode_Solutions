#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        queue<int> q;
        
        for (auto x : nums)
                if (x)
                    q.push(x);
        
        int indx = 0;
        
        while (!q.empty())
            nums[indx++] = q.front(), q.pop();
        
        while (indx < (int) nums.size())
                nums[indx++] = 0;
        
    }
};