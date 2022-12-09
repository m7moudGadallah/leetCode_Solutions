#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    inline int countBits(int n) {
        int cnt{0};
        while (n)
            n >>= 1, ++cnt;
        
        return cnt;
    }
public:
    int concatenatedBinary(int n) {
        long long ans{0}, modulo= {1000000007};
        for (int i = 1; i <= n; ++i)
            ans = (((ans << countBits(i)) % modulo) + i) % modulo;

        return ans;
    }
};