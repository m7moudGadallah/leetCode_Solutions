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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        
        if (!list2)
            return list1;
        
        ListNode *list = list1;

        if (list1->val <= list2->val)
            list1 = list1->next;
        else
            list = list2, list2 = list2->next;
        
        ListNode *curr = list;

        while (true)
        {
            if (!list1 or !list2)
                break;

            if(list1->val <= list2->val)
                curr->next = list1, list1 = list1->next;
            else
                curr->next = list2, list2 = list2->next;
            
            curr = curr->next;
        }

        if (list1)
            curr->next = list1;
        
        if (list2)
            curr->next = list2;
        
        list1 = nullptr;
        list2 = nullptr;
        
        delete(list1);
        delete(list2);

        return list;
    }
};