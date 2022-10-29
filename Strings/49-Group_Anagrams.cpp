#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = (int) strs.size();

        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < n; ++i)
        {
            string s = strs[i];

            sort(s.begin(), s.end());

            mp[s].emplace_back(strs[i]);
        }

        vector<vector<string>> ans(mp.size());

        auto it = mp.begin();

        for (auto &v : ans)
            v = it->second, ++it;
        

        return ans;
    }
};