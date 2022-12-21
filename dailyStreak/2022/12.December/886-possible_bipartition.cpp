#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<vector<int>> graph;
    vector<int> biGraph;

    inline vector<vector<int>> createGraph(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);

        for (auto &x : dislikes) {
            graph[x[0]].emplace_back(x[1]);
            graph[x[1]].emplace_back(x[0]);
        }

        return graph;
    }

    inline bool bfs(int node) {
        queue<int> q;
        q.push(node);
        biGraph[node] = 1;

        while (!q.empty()) {
            node = q.front();

            for (auto &snode : graph[node]) {
                if (biGraph[snode] == biGraph[node])
                    return false;
                
                if (!biGraph[snode])
                    q.push(snode);
                biGraph[snode] = -biGraph[node];
            }

            q.pop();
        }

        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        graph = createGraph(n, dislikes);
        biGraph = vector<int>(n+1);

        for (int i = 1; i <= n; ++i)
            if (!biGraph[i] and !bfs(i))
                return false;

        return true;
    }
};