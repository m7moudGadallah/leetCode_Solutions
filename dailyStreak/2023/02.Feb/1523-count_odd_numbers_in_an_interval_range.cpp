#include<bits/stdc++.h>

using namespace std;
/*
    # Intuition
        we know that number of odd numbers from `1` to `n` is equal to `n/2` with ceilling means when `n=5` `ans=ceil(5/2.0)` so `ans=3` otherwise `n=4` `ans=2`

    # Approach
        so we get number of odds of `low` then subtract them from `high`

    `note` n&1 ==> if number is odd

    # Complexity
        - Time complexity: O(1)

        - Space complexity: O(1)
*/

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