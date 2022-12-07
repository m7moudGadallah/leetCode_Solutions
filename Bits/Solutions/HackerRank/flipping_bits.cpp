#include <bits/stdc++.h>

using namespace std;

long flippingBits(long n) {
    return (long(1)<<32) + ~n;
}