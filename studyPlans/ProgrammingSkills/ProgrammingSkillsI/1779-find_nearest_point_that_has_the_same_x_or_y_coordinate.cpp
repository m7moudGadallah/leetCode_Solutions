#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int ans = -1, mn = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if ( x == points[i][0] or  y == points[i][1]) {
                int tmp = abs(x - points[i][0]) + abs(y - points[i][1]);

                if (tmp < mn)
                    mn = tmp, ans = i;
            }
        }

        return ans;
    }
};