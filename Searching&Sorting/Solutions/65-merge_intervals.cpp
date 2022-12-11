#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());


        vector<vector<int>> ans;

        for (const auto &x : intervals)
        {
            if (ans.empty())
                ans.emplace_back(x);
            else
            {
                auto tmp = ans.back();

                if (x[0] <= tmp[1])
                {
                    tmp[1] = max(tmp[1], x[1]);
                    ans.pop_back();
                    ans.emplace_back(tmp);
                }
                else
                    ans.emplace_back(x);
            }
        }

        return ans;
    }
};