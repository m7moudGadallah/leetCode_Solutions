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
private:
    vector<int> data;
public:
    Solution(ListNode* head) {
        ListNode *pn = head;

        while (pn) {
            data.emplace_back(pn->val);
            pn = pn->next;
        }
    }
    
    int getRandom() {
        return this->data[rand()%data.size()];    
    }
};