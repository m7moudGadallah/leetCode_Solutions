/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

// # Intuition
// we need to get longest subarray that have only 2 distinct numbers so how we do that

// # Approach
// we need to start from begining `p` and also need to use hash table to count number fruits we have from each tree and at each step we check if we have `2 trees` so that we need and if not we will more than 2 trees so we keep moving `p` forward until we have exactly 2 tree `i.e` `map.size()<2`

// # Complexity
// - Time complexity:
// O(n)

// - Space complexity:
// O(n) when `n` is `map.size()`

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> freq;
        int cnt = 0, mx = 0, p = -1;

        for (int i = 0; i < n; ++i) {
            if (!i)     p = i;

            ++freq[fruits[i]], ++cnt;

            while (freq.size() > 2) {
                int &fruit = fruits[p];

                --freq[fruit];
                if (freq[fruit] <= 0)   freq.erase(fruit);
                ++p, --cnt;
            }


            mx = max(mx, cnt);
        }

        return mx;
    }
};