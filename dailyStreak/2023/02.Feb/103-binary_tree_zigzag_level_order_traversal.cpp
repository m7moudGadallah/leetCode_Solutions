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

/**
 * @brief https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/solutions/3204915/c-solution-using-bfs/
 */

class Solution {
private:
    vector<vector<int>> ans;
    void bfs(TreeNode* root) {
        if (!root)      return;

        queue<pair<TreeNode*, int>> qu;       //qu will contains (value, level)
        ans.emplace_back(vector<int>{root->val});        //add root to ans

        if (root->left)                 //push left node if current node already have left node
            qu.push(make_pair(root->left, 1));
        
        if (root->right)                //push right node if current node already have right node
            qu.push(make_pair(root->right, 1));
        

        while (!qu.empty()) {
            TreeNode* currNode = qu.front().first;
            int level = qu.front().second;
            qu.pop();
            if (ans.size() == level)     ans.emplace_back(vector<int>{});        //initialize vector of currlevel if we don't have
            ans[level].emplace_back(currNode->val);     //add current node to the vector of it's level

            if (currNode->left)                 //push left node if current node already have left node
                qu.push(make_pair(currNode->left, level+1));
            
            if (currNode->right)                //push right node if current node already have right node
                qu.push(make_pair(currNode->right, level+1));
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bfs(root);
        int n = ans.size();
        for (int i = 1; i < n; i += 2)
            reverse(ans[i].begin(), ans[i].end());
        return ans;
    }
};