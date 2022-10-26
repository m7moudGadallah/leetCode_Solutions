#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> occ;            //filling sit with char of allowed to check occurence

        for (const auto &ch : allowed)
            occ.insert(ch);

        int cnt{0};

        for (const auto &word : words)
        {
            bool flag{true};        //to check if we find just one char not in allowed so we switch it to false and break
            for (const auto &ch : word)
            {
                if (!occ.count(ch))
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                ++cnt;
        }

        return cnt;
    }
};