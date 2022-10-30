#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        sort(nums.rbegin(), nums.rend());
        
        int n1 = nums.front(), n2 = *(++nums.begin());
        
        --n1, --n2;
        
        return n1 * n2;
    }
};