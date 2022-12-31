#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> grid;
    int empty, r, c;
    int dfs(int i, int j) {
        if (i < 0 or i >= r or j < 0 or j >= c or grid[i][j] == -1)     return 0;

        if (grid[i][j] == 2)    return empty < 0;

        grid[i][j] = -1;
        --empty;

        int numOfPaths = dfs(i+1, j) + dfs(i, j+1) + dfs(i-1, j) + dfs(i, j-1);
        grid[i][j] = 0;
        ++empty;
        return numOfPaths;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        r = grid.size(), c = grid.front().size();
        this->grid = grid;
        empty = 0;

        int si, sj;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1)
                    si = i, sj = j;
                
                empty += (!grid[i][j]);
            }
        }

        return dfs(si, sj);
    }
};