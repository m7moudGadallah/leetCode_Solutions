#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();

        if (n * m != r * c)
            return mat;
        
        int i = 0, j = 0;
        vector<vector<int>> ans(r, vector<int>(c));

        for (auto &x : mat) {
            for (auto &y : x) {
                ans[i][j++] = y;

                if (j >= c)
                    ++i, j = 0;        
            }
        }

        return ans;
    }
};