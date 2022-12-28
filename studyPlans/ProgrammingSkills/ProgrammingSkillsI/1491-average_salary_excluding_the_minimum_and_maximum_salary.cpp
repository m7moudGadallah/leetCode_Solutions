#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int mx = INT_MIN, mn = INT_MAX;
        double tot = 0;

        for (auto &x : salary)
            mx = max(mx, x), mn = min(mn, x), tot += x;
        
        return (tot - (mx+mn)) / (salary.size()-2);
    }
};