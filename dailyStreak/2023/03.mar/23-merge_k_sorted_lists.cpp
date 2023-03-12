/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &list : lists) {
            ListNode *pn = list;
            while (pn) {
                pq.push(pn->val);
                pn = pn->next;
            }
        }

        ListNode *head = nullptr;
        if (pq.empty())
            return head;
        
        head = new ListNode(pq.top());
        pq.pop();
        ListNode* pn = head;

        while (not pq.empty()) {
            pn->next = new ListNode(pq.top());
            pq.pop();
            pn = pn->next;
        }

        return head;
    }
};