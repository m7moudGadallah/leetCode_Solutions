/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    inline bool isValid(const vector<int>& time, long long expTime, long long totalTrips) {
        long long trips = 0;
        
        //calc each bus can make how many trips in this time and get total number of trips
        for (const auto & t : time)
            trips += expTime / t;

        return trips >= totalTrips;     // check if buses can make number of trips greater than or equal needed trips
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1,
                r = *min_element(time.begin(), time.end()) * (long long)(totalTrips),
                ans = r;
        
        while (l <= r) {
            long long mid = l + ((r-l)>>1);

            if (isValid(time, mid, totalTrips))
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }

        return ans;
    }
};