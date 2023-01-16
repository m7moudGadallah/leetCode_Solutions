/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isOverlapped(vector<int> &x, vector<int> &y) {
        return  !(x[1] < y[0]  or y[1] < x[0]);
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size(), p = 0;

        if (!n) {       // already intervals is empty
            ans.emplace_back(newInterval);
            return ans;
        }

        //find pos of new interval
        while (p < n) {
            if (isOverlapped(intervals[p], newInterval) or newInterval[0] < intervals[p][0])
                break;
            
            ans.emplace_back(intervals[p++]);
        }

        if (p >= n) { //it means that new interval is at the end of intervals
            ans.emplace_back(newInterval);
            return ans;
        }
        
        //insert new interval
        if (isOverlapped(intervals[p], newInterval))
            ans.emplace_back(vector<int> ({min(intervals[p][0], newInterval[0]), max(intervals[p][1], newInterval[1])}));
        else
            ans.emplace_back(newInterval);

        //check there is no overlaps
        while (p < n) {
            if (isOverlapped(ans.back(), intervals[p])) {
                int idx = ans.size() - 1;
                ans[idx][0] = min(ans[idx][0], intervals[p][0]);
                ans[idx][1] = max(ans[idx][1], intervals[p][1]);
            }
            else
                ans.emplace_back(intervals[p]);
            
            ++p;
        }

        return ans;
    }
};