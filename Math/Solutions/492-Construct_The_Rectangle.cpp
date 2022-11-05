#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int tmp{(int) sqrt(area)};

        for (int i = tmp; i >= 1; --i) {
            if (area % i == 0) {
                return {area / i, i};
            }
        }

        return {area, 1};
    }
};