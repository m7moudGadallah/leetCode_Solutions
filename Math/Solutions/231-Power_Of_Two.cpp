#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n <= 0)
            return false;

        long long  i = 1;

        while (n > i)
            i <<= 1;

        return (n == i);
    }
};