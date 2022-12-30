#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        
        vector<int> flag;

        for (int i = 0; i < n; ++i)
            if (s1[i] != s2[i])
                flag.emplace_back(i);

        if (flag.empty())
            return true;

        if (flag.size() != 2 or !(s1[flag[0]] == s2[flag[1]] and s1[flag[1]] == s2[flag[0]]))
            return false;

        return true;
    }
};
