/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int partitionString(string s) {
        unordered_set<int> visited;

        int cnt = 0;

        for (auto &ch : s) {
            if (visited.count(ch)) {
                visited.clear();
                ++cnt;
            }
            
            visited.insert(ch);
        }

        cnt += not visited.empty();

        return cnt;
    }
};