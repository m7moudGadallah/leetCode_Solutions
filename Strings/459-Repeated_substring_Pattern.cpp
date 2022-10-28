#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n = (int) s.size();

        for (int len = 1; len <= n / 2; ++len)
        {
            if (n % len)
                continue;

            bool flag = true;

            string t = s.substr(0, len);
            for (int i = len; i < n; i += len)
            {
                if (s.substr(i, len) != t)
                {
                    flag = false;
                    break;
                }
            }
            
            if (flag)
                return flag;
        }

        return false;
    }
};