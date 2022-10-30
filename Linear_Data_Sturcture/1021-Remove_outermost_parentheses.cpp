#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> stk;
        string ans;

        for (const auto &x : s)
        {
            if (stk.empty())
            {
                stk.push(x);
                continue;;
            }

            if (x == '(')
                stk.push(x), ans.push_back(x);
            else
            {
                stk.pop();

                if (stk.empty())
                    continue;
                
                ans.push_back(x);
            }
        }

        return ans;
    }
};
