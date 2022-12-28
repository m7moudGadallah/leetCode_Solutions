#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int odds(int n) {
        return (n/2) + (n&1);
    }
public:
    int countOdds(int low, int high) {
        if (!low)
            return odds(high);
        return odds(high) - odds(low-1);
    }
};