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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 and !list2)  return list1;

        if (!list1) return list2;
        if (!list2) return list1;

        ListNode *mList;

        if (list1->val <= list2->val)
            mList = list1, list1 = list1->next;
        else
            mList = list2, list2 = list2->next;
        
        ListNode* curr = mList;

        while (list1 and list2) {
            if (list1->val <= list2->val)
                curr->next = list1, list1 = list1->next;
            else
                curr->next = list2, list2 = list2->next;
            
            curr = curr->next;
        }

        if (list1)
            curr->next = list1;
        
        if (list2)
            curr->next = list2;
        

        return mList;
    }
};