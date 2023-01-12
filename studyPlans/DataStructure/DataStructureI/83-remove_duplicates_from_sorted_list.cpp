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
private:
    void deleteNode(ListNode *prev) {
        ListNode *tmp = prev->next;

        prev->next = tmp->next;

        delete tmp;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head or !head->next)       return head;

        ListNode *prev = head;
        ListNode *curr = head->next;

        while (curr) {
            if (prev->val == curr->val) {
                deleteNode(prev);
                curr = prev->next;
                continue;
            }
            
            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};
