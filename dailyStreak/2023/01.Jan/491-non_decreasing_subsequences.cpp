/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> arr;
    set<vector<int>> vaildSubs;
    void generateSubsequence(vector<int> &currSub, int idx) {
        if (idx >= (int) arr.size()) {
            if (currSub.size() > 1)   vaildSubs.insert(currSub);
            return;
        }

        //include this element to curr subsequenc if it's greater than last element in it so it will make subsequence increasing
        if (currSub.empty() or currSub.back() <= arr[idx]) {
            currSub.emplace_back(arr[idx]);
            generateSubsequence(currSub, idx+1);
            //excluding this element from current subsequenc
            currSub.pop_back();
        }
        generateSubsequence(currSub, idx+1);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        this->arr = nums;
        vector<int> currSub;
        generateSubsequence(currSub, 0);
        vector<vector<int>> ans;

        for (auto &x : vaildSubs)
            ans.emplace_back(x);
        
        return ans;
    }
};