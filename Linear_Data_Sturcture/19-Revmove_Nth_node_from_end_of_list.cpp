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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if (!head)
            return head;

        ListNode* dummy = new ListNode(0, head);

        ListNode* left = dummy;
        ListNode* right = head;

        while (n--)
            right = right->next;
        
        while (right)
            left = left->next, right = right->next;
        
        ListNode* pn = left->next;
        left->next = left->next->next;
        
        delete(pn);
        
        head = dummy->next;
        
        delete(dummy);

        return head;
    }
};