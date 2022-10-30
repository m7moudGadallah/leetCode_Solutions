#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
vector<vector<int>> dp;

int pacalVal(int r, int c)
{
    if (c == 0 or c == r)
        return 1;
    
    if (dp[r][c])
        return dp[r][c];
    
    return dp[r][c] = pacalVal(r - 1, c) + pacalVal(r - 1, c - 1);
}

vector<int> getRow(int row)
{
    vector<int> v(row + 1);

    for (int i = 0; i <= row; i++)
        v[i] = pacalVal(row, i);

    return v;
}

public:
    vector<vector<int>> generate(int numRows) {
        dp.resize(numRows, vector<int>(numRows));

        vector<vector<int>> mat(numRows);

        for (int i = 0; i < numRows; i++)
            mat[i] = getRow(i);

        
        return mat;
    }
};