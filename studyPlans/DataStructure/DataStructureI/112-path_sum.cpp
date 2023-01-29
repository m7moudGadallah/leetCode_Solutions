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

// path I want to check is from root to leaf and sum all values of this nodes and when I reach leaf I will check if sum equal to target or not

// Approach
// Simple we will traverse left path and check if it valid or not and check right path so
// basecases
// - if root null so it's not valid path
// - if root is a leaf now i'll check if sum is equal target or not

// Complexity
// Time complexity:
// O(n)

// Space complexity:
// O(1)
 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum, int currSum = 0) {
        if (!root)      return false;
        if (!root->left and !root->right)       return targetSum == (currSum + root->val);
        return hasPathSum(root->left, targetSum, currSum+root->val) or hasPathSum(root->right, targetSum, currSum+root->val);
    }
};