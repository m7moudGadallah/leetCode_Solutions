#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (!num) {
            return "0";
        }

        string hexMap{"0123456789abcdef"}, ans{""};

        unsigned int n = num;

        while (n) {
            ans = hexMap[n % 16] + ans;
            n /= 16;
        }

        return ans;
    }
};