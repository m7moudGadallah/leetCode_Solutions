/**
 *  @author Author: Mahmoud Gadallah
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
private:
    unordered_map<string, int> visited;
    vector<TreeNode*> ans;
    
    /**
     * @brief preorder traversal
     * 
     * we represent each subtree on string and store these strings on hash map and then check if we have a duplicate or not
     * 
     * @param root 
     * @return string 
     */
    string dfs(TreeNode* root) {
        if (!root)
            return "";
        
        string subTree = to_string(root->val) + "," + dfs(root->left) + "," +dfs(root->right);

        if (visited[subTree] == 1)
            ans.emplace_back(root);
        ++visited[subTree];
        
        return subTree;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return this->ans;
    }
};