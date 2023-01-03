#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        int n  = s.size();

        auto conv = [&] (int n) {
            return (char)('a' + (n-1));
        };

        string ans = "";

        for (int i = 0; i < n; ++i) {
            if (i + 2 < n and s[i+2] == '#')
                ans += conv((s[i]-'0')*10 + (s[i+1]-'0')), i += 2;
            else
                ans += conv(s[i]-'0');
        }
        
        return ans;
    }
};