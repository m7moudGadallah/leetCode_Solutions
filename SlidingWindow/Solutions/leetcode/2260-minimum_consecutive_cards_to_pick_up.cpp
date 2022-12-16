#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int len(int &l, int &r) {
        return r - l + 1;
    }
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp;
        int n = cards.size();
        int mn = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (mp.count(cards[i]))
                mn = min(mn, len(mp[cards[i]], i));
            
            mp[cards[i]] = i;
        }

        return (mn == INT_MAX) ? -1 : mn;
    }
};