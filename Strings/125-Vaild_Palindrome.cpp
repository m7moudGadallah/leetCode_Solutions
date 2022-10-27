#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        string t{""};

        for (const auto &x : s)
        {
            if (isalnum(x))
                t.push_back(tolower(x));
        }

        int l{0}, r{(int) t.size() - 1};

        while (l < r)
            if (t[l++] != t[r--])
                return false;
        
        return true;
    }
};