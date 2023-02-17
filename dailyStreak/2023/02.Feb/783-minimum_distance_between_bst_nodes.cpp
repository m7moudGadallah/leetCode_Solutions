/**
 *  Author: Mahmoud Gadallah
 *  LeetCode Account: https://leetcode.com/m7moudGadallah/
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

/**
 * @brief this problem Explanation 
 * @link https://leetcode.com/problems/minimum-distance-between-bst-nodes/solutions/3196459/simple-c-solution-beats-100/
 */

class Solution {
private:
    int mn = 1'000'000'000;
    TreeNode* child = nullptr;
    
    /**
     * @brief inordertraversal
     * 
     * @param root 
     */
    void dfs(TreeNode* root) {
        if (root) {
            dfs(root->left);
            if (child)
                mn = min(mn, root->val-child->val);
            child = root;
            dfs(root->right);
        }
    }
public:
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return mn;
    }
};