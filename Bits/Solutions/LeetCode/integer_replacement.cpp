#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unsigned int integerReplacement(int n) {
        if (n <= 1)
            return 0;

        if ((n&1) == 0)
            return integerReplacement(n>>1) + 1;
        
        if (n == INT_MAX)
            return integerReplacement(1<<30) + 2;
        return min(integerReplacement(n+1), integerReplacement(n-1)) + 1;
    }
};