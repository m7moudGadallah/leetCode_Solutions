#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int idx = 0, n = word1.size(), m = word2.size();
        string ans = "";

        while (idx < min(n, m))
            ans += word1[idx], ans += word2[idx], ++idx;
        
        while (idx < n)
            ans += word1[idx++];
        
        while (idx < m)
            ans += word2[idx++];

        return ans;
    }
};