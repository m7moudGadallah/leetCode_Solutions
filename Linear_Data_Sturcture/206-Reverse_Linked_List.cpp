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
    ListNode* reverseList(ListNode* head) {
        
        if (!head)
            return head;
        
        
        ListNode *Prev = nullptr;
        ListNode *Next = nullptr;
        
        while (head->next)
        {
            Next = head->next;
            head->next = Prev;
            Prev = head;
            head = Next;
        }
        
        head->next = Prev;
        
        return head;
    }
};