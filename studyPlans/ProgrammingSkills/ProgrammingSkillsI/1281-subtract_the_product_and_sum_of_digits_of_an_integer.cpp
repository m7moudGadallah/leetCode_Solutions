#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int calc(int n, int sum = 0, int prod = 1) {
        if (!n)
            return prod - sum;
        
        return calc(n/10, sum + (n%10), prod * (n%10));
    }
public:
    int subtractProductAndSum(int n) {
        if (!n)
            return 0;
        
        return calc(n);
    }
};