#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sumXor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long sumXor(long n) {
    long long cnt{1};
    
    while (n) {
        cnt <<= !(n & 1);
        n >>= 1;
    }
    
    return cnt;
}