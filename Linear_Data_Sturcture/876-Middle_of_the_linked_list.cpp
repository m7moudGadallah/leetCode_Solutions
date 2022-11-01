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
    ListNode* middleNode(ListNode* head) {
        
        if (!head)
                return head;
        
        ListNode* mid = head, *curr = head;
        
        while (curr and curr->next)
        {
            mid = mid->next;
            curr = curr->next->next;
        }
        
        return mid;
    }
};