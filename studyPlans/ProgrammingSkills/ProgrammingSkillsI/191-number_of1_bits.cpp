#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (!n) return 0;

        return (n&1) + hammingWeight(n>>1);
    }
};