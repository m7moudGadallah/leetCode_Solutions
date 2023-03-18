/**
 *  @author Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class BrowserHistory {
private:
    stack<string> backHistory, forwaredHistory;
    void clearHistory(stack<string> &history) {
        while (not history.empty())
            history.pop();
    }
public:
    BrowserHistory(string homepage) {
        clearHistory(backHistory);
        clearHistory(forwaredHistory);
        forwaredHistory.push(homepage);
    }
    
    void visit(string url) {
        clearHistory(backHistory);
        forwaredHistory.push(url);
    }
    
    string back(int steps) {
        while (forwaredHistory.size() > 1 and steps--) {
            backHistory.push(forwaredHistory.top());
            forwaredHistory.pop();
        }

        return forwaredHistory.top();
    }
    
    string forward(int steps) {
        while (not backHistory.empty() and steps--) {
            forwaredHistory.push(backHistory.top());
            backHistory.pop();
        }

        return forwaredHistory.top();
    }
};