#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for (auto &x : s) {
            if (x >= 'A' and x <= 'Z')
                x = 'a' + (x-'A');
        }

        return s;
    }
};