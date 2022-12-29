#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; ++i)
            tasks[i].emplace_back(i);
        sort(tasks.begin(), tasks.end(), [&](vector<int> &x, vector<int> &y){
            return x[0] < y[0];
        });

        priority_queue<pair<int, int>, vector<pair<int, int>> ,greater<>> pq;
        vector<int> ans;
        
        int curr = tasks[0][0], it = 0;

        while (it < n) {
            while (it < n and tasks[it][0] <= curr)
                pq.emplace(make_pair(tasks[it][1], tasks[it][2])), it++;
            
            if (pq.empty()) {
                curr = tasks[it][0];
                continue;
            }
            
            ans.emplace_back(pq.top().second);
            curr += pq.top().first;
            pq.pop();
        }

        while (!pq.empty())
            ans.emplace_back(pq.top().second), pq.pop();

        return ans;
    }
};