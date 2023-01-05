/*
    Author: Mahmoud Gadallah
    LeetCode Account: https://leetcode.com/m7moudGadallah/
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
    ListNode* middleNode(ListNode* head) {
        if (!head)      return head;

        ListNode *slow = head, *fast = head; 

        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};