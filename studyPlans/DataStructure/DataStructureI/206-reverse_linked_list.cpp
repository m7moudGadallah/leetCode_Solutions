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
    ListNode* reverseList(ListNode* head) {
        if (!head or !head->next)       return head;

        ListNode *prev = nullptr;
        ListNode *next = head->next;

        while (next) {
            head->next = prev;
            prev = head;
            head = next;
            next = head->next;
        }
        head->next = prev;
        
        return head;
    }
};