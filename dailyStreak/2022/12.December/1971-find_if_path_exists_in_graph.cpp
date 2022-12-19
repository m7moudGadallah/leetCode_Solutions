#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    inline vector<vector<int>> createGraph(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n);

        for (auto edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }

        return graph;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph = createGraph(n, edges);
        set<int> visited;
        queue<int> waited;
        waited.push(source);

        while (!waited.empty()) {
            if (waited.front() == destination)
                return true;
            
            for (auto &x : graph[waited.front()]) {
                if (!visited.count(x))
                    waited.push(x);
            }

            visited.insert(waited.front());
            waited.pop();
        }

        return false;
    }
};