#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    const int modulo = (int)(1e9) + 7;
    vector<int> dp;

    int countRec(int n) {
        if (n < 4 or dp[n])
            return dp[n];
        
        return dp[n] = ((2*countRec(n-1))%modulo + (countRec(n-3))%modulo) % modulo;
    }
public:
    int numTilings(int n) {
        dp = vector<int>(n+4, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        return countRec(n);
    }
};