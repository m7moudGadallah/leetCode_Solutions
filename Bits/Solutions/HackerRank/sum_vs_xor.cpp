#include <bits/stdc++.h>

using namespace std;

long sumXor(long n) {
    long long cnt{1};
    
    while (n) {
        cnt <<= !(n & 1);
        n >>= 1;
    }
    
    return cnt;
}