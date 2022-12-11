#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool good(const int &rows, const int &n)
    {
        return (long long)rows * (rows + 1) / 2 <= n;
    }
public:
    int arrangeCoins(int n) {
        int l{0}, r{n}, mid{0}, ans{0};

        while (l <= r)
        {
            mid = l + (r - l) / 2;

            if (good(mid, n))
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }

        return ans;
    }
};