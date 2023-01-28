/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

// Intuition
// we want to make stream at each time is sorted so what is the best container for that that's right ordered set you can read about it here

// Approach
// so at each time we take stream we insert it on set
// to implement getIntervals we need to find start of the interval and end of it so we make l pointer at the begining of set and move r pointer until we find value that val > l + 1 so now we know it's the end of the interval we move l to this val

// Complexity
// Time complexity:

// addNum ==> O(log(n))

// getIntervals ==> O(n)

// Space complexity:

// o(n) ==> space of orderset


class SummaryRanges {
private:
    set<int> st;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;

        if (st.empty())     return intervals;

        int l = *st.begin(), r = l;

        for (auto &x : st) {
            if (x == r or x == r + 1)       r = x;
            else {
                intervals.emplace_back(vector<int> {l, r});
                l = x, r = x;
            }
        }

        if (intervals.empty() or intervals.back()[1] != r)      intervals.emplace_back(vector<int> ({l, r}));

        return intervals;
    }
};