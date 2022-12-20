#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> visited;
        queue<int> waited;
        visited.insert(0);
        waited.push(0);

        while (!waited.empty()) {
            for (auto &x : rooms[waited.front()]) {
                if (!visited.count(x))
                    waited.push(x);
            }
            
            visited.insert(waited.front());
            waited.pop();
            if (visited.size() == n)
                return true;
        }

        return false;
    }
};