/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> matrix;
    vector<int> ans;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        int n = matrix.size(),
            m = matrix.front().size(),
            i = 0,
            j = 0;
        
        while (n > 0 && m > 0) {
            retrieveGrid(i, j, n, m);
            ++i, ++j, n -= 2, m -= 2;
        }
        return ans;
    }

private:
    void retrieveGrid(int i, int j, int n, int m) {
        //retrieve top row
        retrieveRow(i, j, m, 1);

        //retrieve last col
        retrieveCol(i + 1, j + m  - 1, n - 1, 1);

        if (n > 1) {
            //retrieve last row
            retrieveRow(i + n - 1, j + m - 2, m - 1, -1);
        }

        if (m > 1) {
            //retrieve first col
            retrieveCol(i + n - 2, j, n - 2, -1);
        }
    }

    void retrieveRow(int i, int j, int steps, int step) {
        if (steps <= 0)
            return;

        ans.emplace_back(matrix[i][j]);
        while (--steps) {
            ans.emplace_back(matrix[i][j + step]);
            j += step;
        }
    }

    void retrieveCol(int i, int j, int steps, int step) {
        if (steps <= 0)
            return;

        ans.emplace_back(matrix[i][j]);
        while (--steps) {
            ans.emplace_back(matrix[i + step][j]);
            i += step;
        }
    }
};