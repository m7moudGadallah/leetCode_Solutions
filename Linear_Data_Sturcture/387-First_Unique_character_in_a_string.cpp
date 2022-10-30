#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26);
    
        for (const auto &x : s)
            freq[x - 'a']++;

        
        for (int i = 0, sz = (int) s.size(); i < sz; ++i)
            if (freq[s[i] - 'a'] == 1)
                return i;

        return -1;
    }
};