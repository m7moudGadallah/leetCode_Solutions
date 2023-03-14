/**
 *  @author Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
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
    int sumNumbers(TreeNode* root, string currStr = "") {
        if (not root) return 0;

        currStr += to_string(root->val);

        if (not root->left and not root->right)
            return stoi(currStr);

        int left = sumNumbers(root->left, currStr);
        int right = sumNumbers(root->right, currStr);

        return left + right;
    }
};