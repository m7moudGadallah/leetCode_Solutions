/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    unordered_map<int, int> ownerArray;
    void classifyArrayValues(vector<int> &nums, int classifier) {
        for (auto &num : nums) {
            if (ownerArray.count(num) and ownerArray[num] == -1)    //already duplicate
                continue;
            else if (ownerArray.count(num) and ownerArray[num] != classifier)
                ownerArray[num] = -1;       // set num as duplicated
            else
                ownerArray[num] = classifier;
        }
    }
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2);

        classifyArrayValues(nums1, 0);
        classifyArrayValues(nums2, 1);

        for (auto &item : ownerArray) {
            if (item.second < 0)       //means this element calssified as -1, so it is duplicated
                continue;
            
            answer[item.second].emplace_back(item.first);
        }

        return answer;
    }
};