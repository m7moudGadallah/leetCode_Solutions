#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());

        int sz = arr.size();

        map<int, vector<pair<int, int>>> mp;

        for (int i = 1; i < sz; ++i)
            mp[(arr[i] - arr[i - 1])].emplace_back(make_pair(arr[i - 1], arr[i]));
        

        vector<vector<int>> ans(mp.begin()->second.size(), vector<int>(2));

        int i = 0;

        for (auto x : mp.begin()->second)
            ans[i][0] = x.first, ans[i][1] = x.second, ++i;

        return ans;
    }
};