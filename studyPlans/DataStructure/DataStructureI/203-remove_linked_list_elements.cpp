/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

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
    ListNode* removeElements(ListNode* head, int val) {
        
        if (!head)
                return head;
        
        while (head and head-> val == val)
        {
            ListNode* pn = head;
            head = head->next;
            
            delete(pn);
        }
        
        if (!head)
            return head;
        
        ListNode* curr = head;
        ListNode* prev = curr;
        curr = curr->next;
        
        while (curr)
        {
            if (curr->val == val)
            {
                ListNode* pn = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete(pn);
            }
            else
                prev = curr, curr = curr->next;
        }
        
        return head;
        
    }
};