#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size(), mx{0};

        unordered_map<char, int> mp;        //store char and it's positions
        int p = 0;  //pointer

        for (int i = 0; i < len; ++i) {
            if (mp.count(s[i])) {
                while (p < mp[s[i]])
                    mp.erase(s[p++]);
                ++p;
            }

            mp[s[i]] = i;
            mx = max(mx, i-p + 1);
        }

        return mx;
    }
};