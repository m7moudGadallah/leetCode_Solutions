/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = mat.size();

        for (int i = 0; i < n; ++i)
            pq.push(make_pair(count(mat[i].begin(), mat[i].end(), 1), i));
        
        vector<int> ans;

        while (!pq.empty() and k--)
            ans.emplace_back(pq.top().second), pq.pop();
        
        return ans;
    }
};