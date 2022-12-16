#include<bits/stdc++.h>

using namespace std;

class MyQueue {
private:
    stack<int> queue;
public:
    MyQueue() {

    }
    
    void push(int x) {
        stack<int> tmpStack;

        while (!queue.empty())
            tmpStack.push(pop());
        
        queue.push(x);

        while (!tmpStack.empty()) {
            queue.push(tmpStack.top());
            tmpStack.pop();
        }   
    }
    
    int pop() {
        int ele = queue.top();
        queue.pop();
        return ele;
    }
    
    int peek() {
        return queue.top();
    }
    
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */