#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, mx = 0;

        while (l < r) {
            mx = max(mx, (r-l) * min(height[l], height[r]));

            (height[l] < height[r]) ? ++l : --r;
        }

        return mx;
    }
};