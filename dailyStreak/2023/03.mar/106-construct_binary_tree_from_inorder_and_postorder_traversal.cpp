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
private:
    unordered_map<int, int> idxOf;
    vector<int> inordered, postorder;
    TreeNode* buildTreeAux(int l, int r) {
        if (l > r)
            return nullptr;
        
        TreeNode *root = new TreeNode(postorder.back());
        postorder.pop_back();

        int idx = idxOf(root->val);

        root->right = buildTreeAux(idx+1, r);
        root->left = buildTreeAux(l, idx);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = indorder.size();
        this->inordered = inorder;
        this->postorder = postorder;

        for (int i = 0; i < n; ++i)
            idxOf[inorder[i]] = i;
        

        return buildTreeAux(0, n-1);
    }
};