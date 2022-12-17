#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    inline long long calc(long long &operand1, long long &operand2, string &op) {
        if (op == "+")
            return operand1 + operand2;
        else if (op == "-")
            return operand1 - operand2;
        else if (op == "*") 
            return operand1 * operand2;
        
        return operand1 / operand2;
    }
    
    inline bool isOp(string &s) {
        return s == "+" or s == "*" or s == "-" or s == "/";
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> operands;

        for (auto &token : tokens) {
            if (isOp(token)) {
                long long opernad2 = operands.top();
                operands.pop();

                long long operand1 = operands.top();
                operands.pop();
                
                operands.push(calc(operand1, opernad2, token));
            }
            else
                operands.push(stol(token));
        }

        return operands.top();
    }
};
