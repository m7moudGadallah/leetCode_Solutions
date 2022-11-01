#include <bits/stdc++.h>

using namespace std;

class MyQueue {
private:
    stack<int> stk;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if (stk.empty())
        {
            stk.push(x);
            return;
        }

        stack<int> tmp_stk;

        while (!stk.empty())
            tmp_stk.push(stk.top()), stk.pop();
        
        stk.push(x);

        while (!tmp_stk.empty())
            stk.push(tmp_stk.top()), tmp_stk.pop();
    }
    
    int pop() {
        int tp = stk.top();
        stk.pop();
        return tp;
    }
    
    int peek() {
        return stk.top();
    }
    
    bool empty() {
        return stk.empty();
    }
};