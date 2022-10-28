#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        
        int ch{0}, cnt{0};          //number of charcters and number of segements

        for (const auto &x : s)
        {
            if (x == ' ')
                cnt += (ch != 0), ch = 0;
            else
                ++ch;
        }

        if (ch)
            ++cnt;
            
        return cnt;
    }   
};  