#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; ++i)
            arr[i] += arr[i - 1];

        long long ans = arr.back();

        for (int sz = 3; sz <= n; sz += 2) {
            int step = sz-1;
            for (int i = 0, e = n-sz; i <= e; ++i) {
                if (!i)
                    ans += arr[i+step];
                else
                    ans += arr[i+step] - arr[i-1];
            }
        }

        return ans;
    }
};