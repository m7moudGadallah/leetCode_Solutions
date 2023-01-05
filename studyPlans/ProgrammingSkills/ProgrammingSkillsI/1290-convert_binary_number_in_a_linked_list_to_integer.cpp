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
    int getDecimalValue(ListNode* head) {
        if (!head)      return 0;

        int ans = 0;

        while (head)
            ans = ans * 2 + head->val, head = head->next;
        
        return ans;
    }
};