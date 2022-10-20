#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = (int) s.size();

        vector<int> freq(26, 0);               //freqency array of characters

        auto conv = [](const char &ch){return ch - 'a';}; //lamda to convert from char to int (0 -> 25)


        for (int i = 0; i < n; i++)     //iterate over strings and add it to freq
        {
            freq[conv(s[i])]++;     //adding it to freq
            freq[conv(t[i])]--;     //removing it to freq
        }

        freq[conv(t[n])]--;

        for (int i = 0; i < 26; ++i)
            if (freq[i])      //if we have an element it's freq not zero so we return it
                return (char) (i + 'a');

        return ' ';
    }
};