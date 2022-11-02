#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        long long y{0}, z{x};

        if (x < 0)
            return false;

        while (z)
        {
            y = y * 10 + z % 10;
            z /= 10;
        }

        return (x == y);
    }
};