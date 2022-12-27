#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> diff(n);

        for (int i = 0; i < n; ++i)
            diff[i] = capacity[i] - rocks[i];
        
        sort(diff.begin(), diff.end());

        int cnt = 0;

        int it = 0;

        while (it < n and !diff[it])
            ++cnt, ++it;

        while(it < n) {
            additionalRocks -= diff[it];

            if (additionalRocks < 0)
                return cnt;
            
            ++cnt, ++it;
        }

        return cnt;
    }
};