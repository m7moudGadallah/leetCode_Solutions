#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {

        if (n < 2)
            return 1;
        
        int fs{1}, sc{1}, ans{0};

        for (int i = 2; i <= 2; ++i)
        {
            ans = fs + sc;

            fs = sc, sc = ans;
        }

        return ans;
    }
};