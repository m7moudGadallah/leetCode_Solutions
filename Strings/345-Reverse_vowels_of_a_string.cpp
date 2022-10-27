#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {

        int l{0}, r{(int) s.size() -1};

        auto isVol = [&] (const char &x) {
            return x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u';
        };

        while (l < r)
        {
            bool left_is_vowel = isVol(tolower(s[l]));
            bool right_is_vowel = isVol(tolower(s[r]));
            
            if (left_is_vowel and right_is_vowel)
                swap(s[l++], s[r--]);
            

            if (!left_is_vowel)
                ++l;
            
            if (!right_is_vowel)
                --r;
        }

        return s;
    }
};