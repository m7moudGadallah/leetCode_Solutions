/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/**
 * @brief Problem Explanation
 * @link https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/solutions/3218013/c-solution-beats-more-than-97/
 */


class Solution {
private:
    vector<int> weights;
    int days;
    /**
     * @brief check if current capcity is valid or not
     * 
     * @param cap capcity
     * @return if we can transport packages in a number of days wanted
     * @return false if we can't transport packages
     */
    bool isValid(int cap) {
        int currW = 0, numOfDays = 0;   //currW ==> current weight

        for (auto &w : weights) {
            currW += w;

            if (currW > cap)        //if current weight is over ship capacity so we add a day and leave current packedge to another day
                ++numOfDays, currW = w;
        }
        
        ++numOfDays;        //we already have remaining packages
        return numOfDays <= days;
    }
public:
    /**
     * @brief get min capacity of the ship that can transport packages on specific days
     * 
     * @param weights packages weight
     * @param days we want to transport these packages in 
     * @return int min capacity of the ship
     */
    int shipWithinDays(vector<int>& weights, int days) {
        this->weights = weights;
        this->days = days;
        int l = 0, r = 0, mid = 0, ans = -1;

        for (auto &w : weights)     //get l and r values
            l = max(l, w), r += w;

        while (l <= r) {
            mid = l + ((r-l)>>1);

            if (isValid(mid))
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }

        return ans;
    }
};