#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = (int) s.size();

        if (s.rfind(' ') == string::npos)
            return n;
        
        int i = n - 1;

        while (i < n and s[i] == ' ')
            --i;

        int pos = s.rfind(' ', i);

        if (pos == string::npos)
            return i + 1;

        return i - pos;
    }
};