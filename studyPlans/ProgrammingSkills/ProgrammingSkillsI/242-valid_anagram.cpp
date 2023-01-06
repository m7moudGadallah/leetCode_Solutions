/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = (int) s.size(), m = (int) t.size();

        if (n != m)
            return false;

        vector<int> freq(26);

        for (int i = 0; i < n; ++i)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (const auto &x : freq)
            if (x)
                return false;
        
        return true;
    }
};