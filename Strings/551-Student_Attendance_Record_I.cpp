#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        
        int a{0}, l{0};

        for (const auto &x : s)
        {
            a += (x == 'A');
            l += (x == 'L') ? 1 : -l;

            if (l > 3)
                return false;
            
            if (a > 1)
                return false;
        }

        return true;
    }
};