/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle(numRows);
        pascalTriangle[0].emplace_back(1);

        for (int i = 0; i < numRows; i++) {
            pascalTriangle[i].resize(i+1);

            pascalTriangle[i][0] = 1;
            pascalTriangle[i][i] = 1;
            
            for (int j = 1; j < i; j++) {
                pascalTriangle[i][j] = pascalTriangle[i-1][j-1] + pascalTriangle[i-1][j];
            }
        }

        return pascalTriangle;
    }
};