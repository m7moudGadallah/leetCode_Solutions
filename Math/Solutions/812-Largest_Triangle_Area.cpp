#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    double getArea(vector<int> &a, vector<int> &b, vector<int> &c) {
        return 0.5 * abs(a[0]*(b[1]-c[1]) + b[0]*(c[1]-a[1]) + c[0]*(a[1]-b[1]));
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n{(int) points.size()};
        double mx{0};

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    mx = max(getArea(points[i], points[j], points[k]), mx);
                } 
            }
        }

        return mx;
    }
};