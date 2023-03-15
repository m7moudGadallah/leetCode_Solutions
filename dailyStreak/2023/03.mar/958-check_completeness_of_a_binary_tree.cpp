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

/*
    problem Explanation: https://leetcode.com/problems/check-completeness-of-a-binary-tree/solutions/3300781/c-solution/
*/
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool haveNotComp = false;          //have not complete node means node have `left node` only or not have `left` either `right`

        while (not q.empty()) {
            TreeNode* currNode = q.front();
            q.pop();
            
            bool haveLeft = (currNode->left != nullptr),
                haveRight = (currNode->right != nullptr);
            

            if (not haveLeft and haveRight)     return false;

            if (haveNotComp and (haveLeft or haveRight))    return false;
            
            if (haveLeft)
                q.push(currNode->left);
            else
                haveNotComp = true;
            

            if (haveRight)
                q.push(currNode->right);
            else
                haveNotComp = true;
        }
    }
};