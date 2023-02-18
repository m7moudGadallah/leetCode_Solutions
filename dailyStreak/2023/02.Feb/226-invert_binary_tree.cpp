/**
 * @author Mahmoud Gadallah
 * @link LeetCode Account: https://leetcode.com/m7moudGadallah/
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
 * @link https://leetcode.com/problems/invert-binary-tree/solutions/3111267/simple-c-solution/
 */

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