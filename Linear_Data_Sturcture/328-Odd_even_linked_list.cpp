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
    ListNode* oddEvenList(ListNode* head) {

        if (!head or !head->next)
            return head;

        ListNode *evenlist = head->next;
        ListNode *left = head;
        ListNode *right = evenlist;
        ListNode *curr = head->next->next;

        while (curr)
        {
            left->next = curr, left = left->next;

            curr = curr->next;

            if(curr)
                right->next = curr, right = right->next;
            else
                break;
            
            curr = curr->next;
        }

        right->next = nullptr;
        left->next = evenlist;

        return head;
    }
};