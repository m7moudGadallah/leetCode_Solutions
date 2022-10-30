#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt{0};

        int n = grid.size(), m = grid[0].size();

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
                if (grid[i][j] < 0)
                    ++cnt;
                else
                    break;
        }

        return cnt;
    }
};