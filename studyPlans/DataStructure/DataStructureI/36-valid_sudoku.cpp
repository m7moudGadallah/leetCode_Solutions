/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/**
 * Intuition
 * we want to check every column and every row and every box (9 boxes)
 * 
 * Approach
 *  check rows
 *      it's very simple we just iteratre over each row and store it's value in a hash set and if we found duplicate number then we return false
 * 
 *  check columns
 *      the same thing with rows
 *  Check boxes
 *      we know that each box is a matrix of 3x3 so we need to know the beginning of the matrix and iterate over it and also store it's values in hash set and if we found duplicate number then we return fasle
 * 
 * Complexity
 *  Time complexity:
 *      O(N^2) where N = 9
 *  Space complexity:
 *      O(set.size())
*/

class Solution {
private:
    vector<vector<char>> grid;
    bool validRow(int row) {
        unordered_set<char> visited;
        
        for (int i = 0; i < 9; ++i) {
            if (grid[row][i] == '.')
                continue;
            
            if (visited.count(grid[row][i]))
                return false;
            
            visited.insert(grid[row][i]);
        }

        return true;
    }

    bool vaildColumn(int col) {
        unordered_set<char> visited;
        
        for (int i = 0; i < 9; ++i) {
            if (grid[i][col] == '.')
                continue;
            
            if (visited.count(grid[i][col]))
                return false;
            
            visited.insert(grid[i][col]);
        }

        return true;
    }

    bool validBox(int r, int c) {
        unordered_set<char> visited;
        
        for (int i = r, ei = r + 3; i < ei; ++i) {
            for (int j = c, ej = c + 3; j < ej; ++j) {
                if (grid[i][j] == '.')
                    continue;
                
                if (visited.count(grid[i][j]))
                    return false;
                
                visited.insert(grid[i][j]);
            }
        }

        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        this->grid = board;

        for (int i = 0; i < 9; ++i)     //check rows and columns
            if (!validRow(i) or !vaildColumn(i))
                return false;
        
        for (int i = 0; i < 9; i += 3) {     //check boxes
            for (int j = 0; j < 9; j += 3) {
                if (!validBox(i, j))
                    return false;
            }
        }

        
        return true;
    }
};