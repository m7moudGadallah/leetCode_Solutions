#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        long long mx = -(1e9), w{0};
        
        for (auto x : accounts)
        {
            w = 0;
            
            for (auto y : x)
                w += y;
            
            mx = max(mx, w);
        }
                
        return mx;
    }
};