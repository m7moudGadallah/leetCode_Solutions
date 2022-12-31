#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    inline double getSlope(const vector<int> &c1, const vector<int> &c2) {
        if (!(c2[0] - c1[0])) {     //specail case that gives us division by zero
            return -1;
        }

        return double(c2[1] - c1[1]) / (c2[0] - c1[0]);
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = (int) coordinates.size();

        if (n <= 2) {
            return true;
        }

        double slope = getSlope(coordinates[0], coordinates[1]);

        for (int i = 2; i < n; ++i) {
            if (getSlope(coordinates[i - 1], coordinates[i]) != slope) {
                return false;
            }
        }

        return true;
    }
};