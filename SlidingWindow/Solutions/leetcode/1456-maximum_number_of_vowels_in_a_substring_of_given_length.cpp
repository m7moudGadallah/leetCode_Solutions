#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    inline bool isVowel(char &c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int cnt = 0, mx = 0;
        int n = s.size();
        int l = 0, r = k;
        
        for (int i = 0; i < k; ++i)
            cnt += isVowel(s[i]);
        
        mx = max(mx, cnt);

        if (mx >= k)
            return k;

        while (r < n) {
            cnt -= isVowel(s[l++]);
            cnt += isVowel(s[r++]);

            mx = max(mx, cnt);

            if (mx >= k)
                return k;
        }

        return mx;
    }
};