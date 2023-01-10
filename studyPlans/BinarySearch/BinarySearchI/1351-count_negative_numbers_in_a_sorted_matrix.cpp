/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int BinSerach(vector<int> &arr) {
        int l = 0, r = arr.size() - 1, mid = 0, ans = -1;

        while (l <= r) {
            mid = l + ((r-l)>>1);

            if (arr[mid] <= -1)
                ans = mid, r = mid -1;
            else
                l = mid + 1;
        }

        return ans;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int cnt = 0;            //count number of items < 0

        for (int i = 0; i < n; ++i) {
            int idx = BinSerach(grid[i]);       //binary serach number <= -1
            cnt += (idx == -1) ? 0 : m - idx;
        }

        return cnt;
    }
};


int main() {
    Solution obj;
    vector<int> arr {3,5};

    return 0;
}