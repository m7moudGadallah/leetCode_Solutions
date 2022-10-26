#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = (int) s.size();
        
        int i = n - 1;

        while (i < n and s[i] == ' ')
            --i;

        int pos = s.rfind(' ', i);

        if (pos == string::npos)
            return n;

        return n - pos - 1;
    }
};