#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndx(26);
        int n = s.size();

        for (int i = 0; i < n; ++i)
            lastIndx[s[i] - 'a'] = i;

        vector<int> ans;        
        int l = 0, r = 0;

        while (r < n) {
            r = lastIndx[s[l] - 'a'];

            for (int i = l; i < r; ++i) {
                if (lastIndx[s[i] - 'a'] > r)
                    r = lastIndx[s[i] - 'a'];
            }

            ans.emplace_back(r-l + 1);
            l = ++r;
        }

        if (l < n)
            ans.emplace_back(r-l + 1);
        
        return ans;
    }
};