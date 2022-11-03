#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    long long oper(const string &op, const long long &x, const long long &y)
    {
        if (op == "+")
            return x + y;
        else if (op == "-")
            return x - y;
        else if (op == "*")
            return x * y;
        else
            return x / y;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;

        long long x{0}, y{0};

        for (const auto & val : tokens)
        {
            if (isdigit(val.back()))
                stk.push(stoi(val));
            else
            {
                x = stk.top();   stk.pop();
                y = stk.top();   stk.pop();

                stk.push(oper(val, y, x));
            }
        }

        return stk.top();
    }
};