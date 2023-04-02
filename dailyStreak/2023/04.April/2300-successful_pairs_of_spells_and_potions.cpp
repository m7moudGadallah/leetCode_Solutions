/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int numOfPotions(vector<int>& potions, long long target, long long success) {
        int m = potions.size(),
            l = 0,
            r = m-1,
            mid = 0,
            ans = m;
        
        while (l <= r) {
            mid = l + ((r-l) >> 1);

            if (target * potions[mid] >= success)
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }

        return m - ans;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(),
            m = potions.size();
        
        vector<int> ans(n);

        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; i++) {
            ans [i] = numOfPotions(potions, spells[i], success);
        }

        return ans;
    }
};