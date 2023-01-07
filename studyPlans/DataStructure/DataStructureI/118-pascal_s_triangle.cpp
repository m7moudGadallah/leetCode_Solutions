/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
    int getVal(int r, int c) {
        if (!c or r == c)       return 1;

        if (dp[r][c])   return dp[r][c];

        return dp[r][c] = getVal(r-1, c-1) + getVal(r-1, c);
    }
    vector<int> getRow(int rowNum) {
        vector<int> row(rowNum+1);

        for (int i = 0; i <= rowNum; ++i)
            row[i] = getVal(rowNum, i);
        
        return row;
    }
public:
    vector<vector<int>> generate(int numRows) {
        dp = vector<vector<int>> (numRows, vector<int>(numRows, 0));

        vector<vector<int>> rows(numRows);

        for (int i = 0; i < numRows; ++i)
            rows[i] = getRow(i);
        
        return rows;
    }
};