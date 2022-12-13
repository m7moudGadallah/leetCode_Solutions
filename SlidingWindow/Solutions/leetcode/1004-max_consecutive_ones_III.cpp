#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int getLen(int l, int r) {
        return r-l + 1;
    }
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = nums.size();
        deque<int> dq;          //store positions of zeroes
        
        int l = 0, r = 0, mx = 0;

        while (r < len) {
            if (!nums[r]) {
                if (!k) {
                    if (dq.empty()) {
                        ++r, l = r;
                        continue;
                    }
                    l = dq.front() + 1;
                    dq.pop_front();
                }
                else
                    --k;

                dq.emplace_back(r);
            }

            mx = max(mx, getLen(l, r));
            ++r;
        }

        return mx;
    }
};