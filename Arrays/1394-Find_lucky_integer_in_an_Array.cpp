#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;
        
        int mx = -1;
        
        for (auto x : arr)
            mp[x]++;
        
        
        for (auto x : mp)
            if (x.first == x.second)
                    mx = max(mx, x.first);
        
        return mx;
    }
};