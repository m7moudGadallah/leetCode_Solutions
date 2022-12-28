#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        for (auto &x : piles)
            pq.push(x);
        
        while (!pq.empty() and k) {
            int curr = pq.top();
            curr -= (curr>>1);
            pq.pop();

            if (curr > 0)
                pq.push(curr);

            --k;
        }

        int tot = 0;
        
        while (!pq.empty())
            tot += pq.top(), pq.pop();

        return tot;
    }
};