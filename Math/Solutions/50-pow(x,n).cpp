#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    double fPow(double x, long long n) {
        if (n <= 0)
            return 1;
        
        double tmp = fPow(x, n>>1);
        return (n&1) ? x*tmp*tmp : tmp*tmp;
    }
public:
    double myPow(double x, long long n) {
        return (n < 0) ? 1.0/fPow(x, -n) : fPow(x, n);
    }
};