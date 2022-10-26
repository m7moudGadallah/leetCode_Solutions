#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        
        int d{0}, mxD{0};           //depth & maxdepth

        auto isParentheses = [&](const char &ch){return ch == '(' or ch == ')';};

        for (const auto &ch : s)
        {
            if (isParentheses(ch))
                d += (ch == '(') ? 1 : -1;

                mxD = max(mxD, d);
        } 

        return (d) ? 0 : mxD;
    }
};