#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<char, char> open_parentheses{{')', '('},
                                 {']', '['},
                                 {'}', '{'}};

    inline bool isOpenParentheses(const char &c)
    {
        return c == '(' or c == '[' or c == '{';
    }

public:
    bool isValid(string s) {
        stack<char> stk;

        for (const auto &x : s){
            if (isOpenParentheses(x))
                stk.push(x);
            else
            {
                if (stk.empty() or stk.top() != open_parentheses[x])
                    return false;
                
                stk.pop();
            }
        }

        return stk.empty();
    }
};