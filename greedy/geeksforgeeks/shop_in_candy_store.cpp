#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int> ans(2);

        if (!K) {
            ans[0] = ans[1] = accumulate(candies, candies+N, 0);
            return ans;
        }

        sort(candies, candies+N);

        int n = N;

        for (int i = 0; i < n; ++i) {
            ans[0] += candies[i];
            n -= K;
        }

        n = -1;
        for (int i = N-1; i > n; --i) {
            ans[1] += candies[i];
            n += K;
        }

        return ans;
    }
};