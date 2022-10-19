#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    inline vector<string> split(const string &s)
    {
        int n = (int) s.size(),i = 0, it = s.find(" ", 0);
        
        vector<string> ans;

        while (it != string::npos)
        {
            ans.emplace_back(s.substr(i, it - i));
            i = it + 1;
            it = s.find(" ", i);
        }

        ans.emplace_back(s.substr(i, n - i));

        return ans;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        unordered_map<string, int> freq;
        
        vector<string> words = split(s1 + " " + s2), ans;

        for (const auto &word : words)
            freq[word]++;

        for (const auto &x : freq)
            if (x.second == 1)
                ans.emplace_back(x.first);
        
        return ans;
    }
};