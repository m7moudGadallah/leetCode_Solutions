#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        if (k >= n)
            return "0";

        stack<char> stk;

        for (auto &x : num) {
            if (!k) {
                if (stk.empty() and x=='0')
                    continue;
                stk.push(x);
                continue;
            }

            while (!stk.empty() and stk.top() > x and k) {
                if (stk.top()-'0')
                    --k;
                stk.pop();
            }

            if (stk.empty() and x=='0')
                continue;
            stk.push(x);
        }

        while (!stk.empty() and k--)
            stk.pop();
        
        string ans = "";

        while (!stk.empty())
            ans += stk.top(), stk.pop();
        
        reverse(ans.begin(), ans.end());

        return (ans.empty()) ? "0" : ans;
    }
};