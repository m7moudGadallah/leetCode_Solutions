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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    ListNode* getMid(ListNode* head) {
        ListNode *slow = head,
            *fast = head,
            *prev = head;
        
        while (fast and fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev)
            prev->next = nullptr;

        return slow;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)      return nullptr;

        ListNode *mid = getMid(head);           //getting mid node
        TreeNode* root = new TreeNode(mid->val);        //make it as root 

        if (head == mid)
            return root;

        root->left = sortedListToBST(head);     //assign all element left mid to left branch of tree
        root->right = sortedListToBST(mid->next);   //assign all element right mid to right branch of tree

        return root;
    }
};