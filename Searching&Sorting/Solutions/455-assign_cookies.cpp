#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int g_indx{0}, s_indx{0}, n{(int) g.size()}, m{(int) s.size()};

        while (g_indx < n and s_indx < m)
            if (g[g_indx] <= s[s_indx])
                ++g_indx, ++s_indx;
            else
                ++s_indx;
        

        return g_indx;
    }
};