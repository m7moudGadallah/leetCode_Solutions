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

// Intuition
// How to invert Binary Tree?
// - by inverting every subtree

// Approach
// So now we will dfs on tree and on root of each subtree we swap it's left and right children

// Complexity
// Time complexity:
// O(n)

// Space complexity:
// O(1)

class Solution {
private:
    void dfs(TreeNode* currRoot) {
        if (!currRoot)      return;

        swap(currRoot->left, currRoot->right);
        dfs(currRoot->left);
        dfs(currRoot->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};