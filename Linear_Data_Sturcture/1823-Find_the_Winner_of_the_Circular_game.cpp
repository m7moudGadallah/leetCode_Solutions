#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        int a = 0; 
        for(int i = 1; i<=n; ++i){
            a = (a + k) % i;
        }
        return a + 1;
    }
};