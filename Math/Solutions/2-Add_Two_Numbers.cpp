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
private:
    inline int sum(const int &val1, const int &val2, int &carry) {
       int ans = val1 + val2 + carry;
        carry = 0;

        if (ans > 9) {
            ans %= 10;
            carry = 1;
        }

        return ans;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        
        if (!l2)
            return l1;
        int carry{0};

        ListNode* sumHead = new ListNode(0);
        ListNode* pn = sumHead;
        ListNode* pl1 = l1;
        ListNode* pl2 = l2;

        while (pl1 and pl2) {
            pn->next = new ListNode(sum(pl1->val, pl2->val, carry));
            pn = pn->next;
            pl1 = pl1->next, pl2 = pl2->next;
        }

        while (pl1) {
            pn->next = new ListNode(sum(pl1->val, 0, carry));
            pn = pn->next;
            pl1 = pl1->next;
        }

        while (pl2) {
            pn->next = new ListNode(sum(pl2->val, 0, carry));
            pn = pn->next;
            pl2 = pl2->next;
        }

        if (carry) {
            pn->next = new ListNode(carry);
        }

        pn = sumHead;
        sumHead = sumHead->next;
        delete(pn);

        return sumHead;
    }
};