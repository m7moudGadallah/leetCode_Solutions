#include<bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    vector<int> ans;
    unordered_set<Node*> visited;
    void dfs(Node* root) {
        if (visited.count(root))    return;

        ans.emplace_back(root->val);
        visited.insert(root);

        for (auto &child : root->children)
            dfs(child);
    }
public:
    vector<int> preorder(Node* root) {
        if (!root)
            return ans;
        dfs(root);
        return ans;
    }
};
