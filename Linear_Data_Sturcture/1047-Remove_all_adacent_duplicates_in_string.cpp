#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string t;

        for (auto x : s)
        {
            if (t.empty())
                t.push_back(x);
            else
                (x == t.back()) ? t.pop_back() : t.push_back(x);
        }

        return t;
    }
};