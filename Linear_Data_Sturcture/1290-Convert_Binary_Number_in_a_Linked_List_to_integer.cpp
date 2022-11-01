#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        if (!head)
            return 0;
        
        int ans = head->val;
        
        while (head->next)
            ans = ans * 2 + head->next->val, head = head->next;
        
        return ans;
        
    }
};