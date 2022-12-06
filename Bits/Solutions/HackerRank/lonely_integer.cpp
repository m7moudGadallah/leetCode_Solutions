#include <bits/stdc++.h>

using namespace std;

int lonelyinteger(vector<int> a) {
    int num{0};
    
    for (const auto &x : a) {
        num ^= x;
    }
    
    return  num;
}