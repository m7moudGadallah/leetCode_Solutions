#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int calcDistance(vector<int> &p1, vector<int> &p2)
    {
        int dx = abs(p2[0] - p1[0]);
        int dy = abs(p2[1] - p1[1]);

        return max(dx, dy);
    }
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int ans{0};

        for (int i = 1; i < (int)points.size(); ++i)
            ans += calcDistance(points[i], points[i - 1]);
            
        return ans;
    }
};
