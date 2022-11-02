#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fib(int n) {
        
        if (n < 2)
            return n;

        int fs{0}, sc{1}, ans{0};

        for (int i = 2; i <= n; ++i)
        {
            ans = fs + sc;

            fs = sc, sc = ans;
        }

        return ans;
    }
};