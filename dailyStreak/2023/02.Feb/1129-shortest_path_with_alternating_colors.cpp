/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n), blue(n);
        vector<int> ans(n, -1);

        for (auto &x : redEdges)     red[x[0]].emplace_back(x[1]);
        for (auto &x : blueEdges)    blue[x[0]].emplace_back(x[1]);

        queue<tuple<int, int, int>> qu;       //node, length, color       [color (0->nothing) (1->red) (-1->blue)]
        set<pair<int, int>> visited;          //node, color
        qu.push(make_tuple(0, 0, 0));
        visited.insert(make_pair(0, 0));
        ans[0] = 0;

        while (!qu.empty()) {
            int node, len, color;
            tie(node, len, color) = qu.front();
            qu.pop();

            if (ans[node] == -1)        ans[node] = len;

            if (color != 1) {
                for (auto &sub:red[node]) {
                    if (visited.count(make_pair(sub, 1)))   continue;

                    qu.push(make_tuple(sub, len+1, 1));
                    visited.insert(make_pair(sub, 1));
                }
            }

            if (color != -1) {
                for (auto &sub:blue[node]) {
                    if (visited.count(make_pair(sub, -1)))      continue;
                    qu.push(make_tuple(sub, len+1, -1));
                    visited.insert(make_pair(sub, -1));
                }
            }
        }

        return ans;
    }
};