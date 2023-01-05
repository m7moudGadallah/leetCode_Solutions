/*
    Author: Mahmoud Gadallah
    LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());     //sorting ballons based on start
        int cnt = 1, shoot = points[0][1];      // cnt-->count of shoots


            // iterate over ballons
            // we greedly take end of ballon to shoot but in some cases there is some
            // ballons it's diameter is smaller
            // Ex:   current shoot = 9    & ballons [[1, 9], [2, 8], [3, 6]] so 1st will brest but 2nd & 3rd are not but if we make our shoot = 6 so we can brest all of them 
            
            // so with each step we min(shoot, x[1])

            //     if current shoot can burst ballon so we skip it
            // otherwise
            //     we want new shoot 


        for (auto &x : points) {
            shoot = min(shoot, x[1]);
            if (shoot < x[0])
                ++cnt, shoot = x[1];
        }
        
        return cnt;
    }
};