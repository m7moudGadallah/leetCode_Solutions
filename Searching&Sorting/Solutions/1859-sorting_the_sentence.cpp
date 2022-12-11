#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        int n{0};

        unordered_map<int, string> mp;

        stringstream ss(s);
        string t{""};
        int indx{0};

        while (ss >> t)
        {
            indx = t.back() - '0';
            t.pop_back();

            mp[indx] = t;

            ++n;
        }

        t.clear();

        for (int i = 1; i < n; ++i)
            t.append(mp[i] + ' ');
        
        t.append(mp[n]);

        return t;
    }
};