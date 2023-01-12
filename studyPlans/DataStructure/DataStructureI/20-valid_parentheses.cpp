/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<char, char> Parentheses{{'(', ')'}, 
                                          {'[', ']'},
                                          {'{', '}'}};
public:
    bool isValid(string s) {
        stack<char> stk;

        for (auto &x : s) {
            bool isOpen = Parentheses.count(x);

            if (!isOpen) {
                if (stk.empty() or Parentheses[stk.top()] != x)        return false;
                
                stk.pop();
            }
            else
                stk.push(x);
        }

        return stk.empty();
    }
};