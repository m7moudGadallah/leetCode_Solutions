#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        int n =(int)deck.size();

        sort(deck.begin(), deck.end());
        
        queue<int> q;
        
        for (int i = 0; i < n; ++i)
            q.push(i);
        
        bool flip {true};
        
        vector<int> ans(n);

        int indx{0};
        
        while (!q.empty())
        {
            if (flip)
                ans[q.front()] = deck[indx++],q.pop();
            else
                q.push(q.front()), q.pop();
            
            flip ^= true;
        }
        
        return ans;
    }
};