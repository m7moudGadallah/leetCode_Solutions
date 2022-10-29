#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int n = (int) s.size();

        int cnt{1}, ch_cnt{0}, ans{0};

        for (int i = 1; i < n; ++i)
        {
            if (s[i] != s[i - 1])
                ch_cnt = cnt, cnt = 0;
            
            ++cnt;

            ans += (ch_cnt and cnt <= ch_cnt);
        }

        return ans;
    }
};