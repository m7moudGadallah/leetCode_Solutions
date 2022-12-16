#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = t.size();

        int j = 0;

        for (auto &x : s) {
            if (x == t[j])
                ++j;
            
            if (j >= n)
                break;
        }

        return n - j;
    }
};