#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {

        map<char, int> freq;        //map to get freqency fo charcaters in string

        for (const auto &x : s)
            freq[x]++;
        
        auto it = freq.begin();
        int ans{0};             //answer value

        /*
            now we iterate over map if char frequency is even we take it but if it's odd in this case
            we check if ans now is odd so we freq[x] - 1 otherwise we take freq[x]
        */
        while (it != freq.end())
        {
            if (it->second % 2 == 0)
                ans += it->second;
            else
                (ans % 2) ? ans += (it->second - 1) : ans += it->second;

            ++it;
        }
        
        return ans;
    }
};