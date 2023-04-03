/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int l = 0,                      //left pointer
            r = people.size()-1,        //right pointer
            numOfBoats = 0,
            cap = 0;    //current capacity
        

        /**
         * every time we will move r pointer (max current weight) 1 step back
         * and check if boat can take person on l pointer (min current weight)
         * then we will move l pointer 1 step forward
         */
        while (l <= r) {
            cap = people[r] + people[l];

            if (cap <= limit)
                ++l;
            
            --r;
            ++numOfBoats;
        }

        return numOfBoats;
    }
};