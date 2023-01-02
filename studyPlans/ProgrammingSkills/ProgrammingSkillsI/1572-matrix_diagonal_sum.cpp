#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();

        int idx = 0;
        int sum = 0;

        while (idx < n)
            sum += mat[idx][idx] + mat[n-idx-1][idx], ++idx;

        if (n&1)
            sum -= mat[n/2][n/2];
        
        return sum;
    }
};