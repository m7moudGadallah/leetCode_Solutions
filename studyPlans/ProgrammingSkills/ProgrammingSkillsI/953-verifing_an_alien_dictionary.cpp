#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> dic(26, 0);

        for (int i = 0; i < 26; ++i)
            dic[order[i]-'a'] = i;
        
        auto comp = [&] (string x, string y) {
            int n = x.size(), m = y.size();

            for (int i = 0; i < min(n, m); ++i) {
                if (dic[x[i]-'a'] == dic[y[i]-'a'])     continue;
                if (dic[x[i]-'a'] > dic[y[i]-'a'])      return false;
                return true;
            }

            if (n > m)
                return false;

            return true;
        };



        int sz = words.size();

        for (int i = 1; i < sz; ++i) {
            if (!comp(words[i-1], words[i]))
                return false;
        }
        return true;
    }
};