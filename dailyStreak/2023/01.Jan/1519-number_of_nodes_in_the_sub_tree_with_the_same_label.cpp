/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/**Approach
 * how to count labels that equal to label of parent?
 *      what about counting labels of each subtree then from it we get count of labels for parent
 * 
 * so we create frequency array of 26 element that will represent labels a,b,.....,z and on each subtree we will count number of labels
 * after that we will get number of labels that equal to parent label
 * 
 * Time Complexity: O(26*N)
 * Space Complexity: O(26*N) where 26 is frequency array and N number of call stacks
*/

class Solution {
private:
    vector<int> ans;
    string labels;
    vector<vector<int>> graph;
    void createGraph(vector<vector<int>> &edges) {      //represent adjacency list
        for (auto &edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
    }

    vector<int> dfs(int child, int parent) {
        vector<int> freq(26);       //frequency array of chars from a,b, ....,z
        freq[labels[child]-'a']++;

        for (auto &node : graph[child]) {
            if (node == parent)     continue;

            auto childFreq = dfs(node, child);      //get frequncy of chars of subtree

            for (int i = 0; i < 26; ++i)    freq[i] += childFreq[i];        
        }
        ans[child] = freq[labels[child]-'a'];       //store number of labels that equal to parent label

        return freq;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n);
        graph.resize(n);
        this->labels = labels;
        createGraph(edges);
        
        dfs(0, -1);

        return ans;
    }
};