#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {

        while (b) {
            unsigned int carry = (a&b);
            a ^= b;
            b = carry << 1;
        }

        return a;
    }
};