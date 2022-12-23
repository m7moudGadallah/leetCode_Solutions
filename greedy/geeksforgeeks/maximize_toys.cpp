#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int toyCount(int N, int K, vector<int> arr)
    {
        sort(arr.begin(), arr.end());
        long long tot = 0;
        int cnt = 0;

        for (auto &x : arr) {
            tot += x, K -= x;
            if (K < 0)
                return cnt;
            
            ++cnt;
        }

        return cnt;
    }
};