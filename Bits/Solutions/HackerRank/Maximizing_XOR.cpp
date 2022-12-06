#include <bits/stdc++.h>

using namespace std;

int maximizingXor(int l, int r) {
    int val = l ^ r;
    int mx{1};
    
    while (val)
        val >>= 1, mx <<= 1;
    
    return mx - 1;
}