#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<vector<int>> &graph, int node = 0) {
        path.emplace_back(node);

        if (node == graph.size()-1)
            ans.emplace_back(path);
        
        for (auto &x : graph[node])
            dfs(graph, x);
        path.pop_back();
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph);
        return ans;
    }
};