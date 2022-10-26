#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = (int) strs.size();

        int i = 0;
        char ch = strs.front()[0];

        while (true)
        {
            if (strs.front().size() <= i)
                return strs.front().substr(0, i);
            
            ch = strs.front()[i];

            for (int j = 0; j < n; ++j)
                if (strs[j].size() <= i or strs[j][i] != ch)
                    return strs.front().substr(0, i);

            ++i;
        }

        if (i)
            return strs.front();
        else
            return "";
    }
};