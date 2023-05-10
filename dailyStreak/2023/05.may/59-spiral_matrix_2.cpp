/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int count = 1;
    vector<vector<int>> matrix;
public:
    vector<vector<int>> generateMatrix(int n) {
        matrix.resize(n, vector<int>(n));

        int startRow = 0, startCol = 0;

        while (n > 0) {
            fillGridBroders(startRow, startCol, n, n);
            ++startRow, ++startCol, n -= 2;
        }

        return matrix;
    }

private:
    // Fills bordes of square grid of size numRows x numCols, starting at (startRow, startCol).
    void fillGridBroders(int startRow, int startCol, int numRows, int numCols) {
        // Fill top row
        fillRow(startRow, startCol, numCols, 1);
        // Fill right column
        fillCol(startRow + 1, startCol + numCols - 1, numRows - 1, 1);

        if (numRows > 1) {
            // Fill bottom row
            fillRow(startRow + numRows - 1, startCol + numCols - 2, numCols - 1, -1);
        }

        if (numCols > 1) {
            // Fill left column
            fillCol(startRow + numRows - 2, startCol, numRows - 2, -1);
        }
    }

    // Fills a row of length steps, starting at (row, col), with values incrementing by step.
    void fillRow(int row, int col, int steps, int step) {
        while (steps--) {
            matrix[row][col] = count++;
            col += step;
        }
    }

    // Fills a column of length steps, starting at (row, col), with values incrementing by step.
    void fillCol(int row, int col, int steps, int step) {
        while (steps--) {
            matrix[row][col] = count++;
            row += step;
        }
    }
};