#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    long long int minValue(int a[], int b[], int n)
    {
        sort(a, a+n);
        sort(b, b+n);
        int l = 0, r = n-1;
        long long ans = 0;

        while (r+1)
            ans += a[l++] * b[r--];

        return ans;
    }
};