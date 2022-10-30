#include <bits/stdc++.h>

using namespace std;

class Solution {

private:
    void shiftRight(vector<int> &arr)
    {
        int sz = arr.size();
        int tmp = arr.back();

        for (int i = sz - 1; i > 0; --i)
            arr[i] = arr[i - 1];

        arr[0] = tmp;
    }

public:

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int n = grid.size(), m = grid[0].size();

        k %= (n * m);

        if (!k)
            return grid;

        vector<int> arr(n * m);
        int indx = 0;

        for (auto r : grid)
            for (auto c : r)
                arr[indx++] = c;

        while (k--)
            shiftRight(arr);
        
        vector<vector<int>> mat(n, vector<int>(m));
        
        indx = 0;

        for (auto &r : mat)
            for (auto &c : r)
                c = arr[indx++];

        return mat;
    }
};