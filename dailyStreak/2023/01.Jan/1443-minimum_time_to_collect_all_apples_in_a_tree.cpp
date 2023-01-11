/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<bool> hasApple;
    vector<vector<int>> graph;
    void createGraph(vector<vector<int>>& edges) {
        for (auto &edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
    }

    int dfs(int child, int parent = -1) {
        int totTime = 0, time = 0;          //totTime --> indicate for minTime and time --> indicat time token for childs
        
        for (auto &node : graph[child]) {
            if (node == parent)     continue;

            time = dfs(node, child);        //getting time of each child so if child has an apple will cost us 2s because one second go and another one back

            /**
             * if we have already apples on these path so it's already valid path so we need to take time cost of it
             * so if time > 0 it means this path have apples so it's valid 
            */
            if (time or hasApple[node])        totTime += time + 2;     
        }

        return totTime;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        this->hasApple = hasApple;

        graph.resize(n);
        createGraph(edges);         //creatring graph

        return dfs(0);
    }
};