#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    
    int pascalval(int r, int c)
    {
        if (c == 0 or c == r)
            return 1;
        
        if (dp[r][c])
            return  dp[r][c];
        
        return dp[r][c] = pascalval(r - 1, c) + pascalval(r - 1, c - 1);
    }
    vector<int> getRow(int rowIndex) {
        
        dp.resize(rowIndex + 1, vector<int>(rowIndex + 1));
        
        vector<int> ans(rowIndex + 1);
        
        
        for (int i = 0; i <= rowIndex; ++i)
            ans[i] = pascalval(rowIndex, i);
        
        return ans;
    }
};