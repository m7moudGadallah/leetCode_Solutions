#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = (int) s.size();

        unordered_map<char, char> mp;
        unordered_set<char> token;

        for (int i = 0; i < n; ++i)
        {
            if (mp.count(s[i]))
            {
                if (mp[s[i]] != t[i])
                    return false;
            }
            else
            {
                if (token.find(t[i]) != token.end())
                    return false;
                
                mp[s[i]] = t[i];
                
                token.emplace(t[i]);
            }
        }

        return true;
    }
};