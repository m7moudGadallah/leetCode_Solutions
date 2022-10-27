#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = (int) s.size();

        int indx{0};

        for (const auto &x : t)
        {
            if (indx >= n)
                return true;

            if (x == s[indx])
                ++indx;
        }

        return (indx >= n);
    }
};