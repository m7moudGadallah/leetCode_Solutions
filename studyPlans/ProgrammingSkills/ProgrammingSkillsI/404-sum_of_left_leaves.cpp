/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)      return 0;

        if (root->left and !root->left->left and !root->left->right)
            return root->left->val + sumOfLeftLeaves(root->right);
        
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};