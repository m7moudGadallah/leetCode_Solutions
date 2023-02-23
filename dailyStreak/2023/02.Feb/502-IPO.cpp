/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/**
 * @brief Problem Explanation
 * @link https://leetcode.com/problems/ipo/solutions/3221379/simple-c-solution/
 */

class Solution {
public:
    int findMaximizedCapital(int k, long long w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);

        int i = 0;
        for (auto &project : projects)
            project.first = capital[i], project.second = profits[i++];

        sort(projects.begin(), projects.end());

        priority_queue<int> mxProfits;

        i = 0;
        while (k) {
            while (i < n and projects[i].first <= w)    //keep taking all projects that we can invest on it
                mxProfits.push(projects[i++].second);

            //if currenet capital we have is less than any project capital so we can't invest
            if (mxProfits.empty())
                return w;

            w += mxProfits.top();       //take max profit
            mxProfits.pop();            //remove this project for priority queue
            --k;
        }

        return w;
    }
};