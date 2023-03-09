/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;

        /*
            we keep moving slow (one step for each move)
            & moving fast (two steps for each move) until
            they meet so (there's a cycle)
            other wise if fast reach end node or null so we didn't have a cycle
        */
        while (slow and 
            fast and fast->next) {
            
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        /* 
            if fast reach end node or become null or next node equal null
            so we know that we didn't have a cycle
        */
        if (!fast or !fast->next)
            return nullptr;
        

        /*
            so we need to make slow to point on head and keep moving slow and fast (one step on each move)
            until they point on the same node again
        */
        slow = head;

        while (slow != fast)
            fast = fast->next, slow = slow->next;
        
        return slow;
    }
};