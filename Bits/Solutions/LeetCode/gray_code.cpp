#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        n = (1 << n);
        vector<int> gCode(n);

        for (int i = 0; i < n; ++i)
            gCode[i] = (i ^ (i>>1));
        
        return gCode;
    }
};