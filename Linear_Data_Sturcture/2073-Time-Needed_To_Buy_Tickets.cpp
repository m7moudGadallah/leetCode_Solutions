#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;

        for (int i = 0, sz = tickets.size(); i < sz; ++i)
            q.push(i);
        
        int cnt{0};
        while (tickets[k])
        {
            tickets[q.front()]--;

            if (tickets[q.front()])
                q.push(q.front()), q.pop();
            else
                q.pop();
            
            ++cnt;
        }


        return cnt;
    }
};