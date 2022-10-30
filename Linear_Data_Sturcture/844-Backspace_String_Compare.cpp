#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> stk1, stk2;

        for (auto x : s){
            if (x == '#'){
                if (stk1.empty())
                    continue;
                else
                    stk1.pop();
            }
            else
                stk1.push(x);
        }

        for (auto x : t){
            if (x == '#'){
                if (stk2.empty())
                    continue;
                else
                    stk2.pop();
            }
            else
                stk2.push(x);
        }

        if (stk1.size() != stk2.size())
            return false;
        
        while (!stk1.empty()){
            if (stk1.top() != stk2.top())
                return false;
            
            stk1.pop(), stk2.pop();
        }

        return true;
    }
};