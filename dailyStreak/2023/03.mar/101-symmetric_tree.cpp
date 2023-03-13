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
private:
    bool dfs(TreeNode *ln, TreeNode *rn) {
        if (!rn or !ln)        return rn == ln;         //if left pointer and rigth pointer is null it will return true otherwise return false
        return (rn->val == ln->val) and dfs(ln->left, rn->right) and dfs(ln->right, rn->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
};