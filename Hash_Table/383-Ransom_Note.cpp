#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        vector<int> freq(26, 0);                //frequency array of character

        auto conv = [](char x){return x - 'a';};        //lamda to convert from character to number from 0 to 25

        for (const auto &ch : magazine)         //filling frequency array with characters of magazine
            freq[conv(ch)]++;
        

        for (const auto &ch : ransomNote)           //looping to check if already ransomNote characters in freq or not
        {
            if (freq[conv(ch)])
                freq[conv(ch)]--;
            else
                return false;
        }

        return true;
    }
};