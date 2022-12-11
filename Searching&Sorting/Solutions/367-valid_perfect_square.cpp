#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {

        if (num == 1)
            return true;
            
        int l{0}, r{num / 2}, mid{0}, ans{0};

        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if ((long long) mid * mid <= num)
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }

        return ((long long) ans * ans == num);
    }
};