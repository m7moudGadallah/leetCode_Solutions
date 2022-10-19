#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        
        unordered_set<int> st; //set of sizes that alice has

        int totA{0}, totB{0};       //total sizes that alice, total sizes that bob has

        for (const auto &x : aliceSizes)
            st.insert(x), totA += x;
        
        totB = accumulate(bobSizes.begin(), bobSizes.end(), 0);

        int diff{totA - totB};
        diff /= 2;

        for (const auto &x : bobSizes)
        {
            unordered_set<int>::iterator it = st.find(x + diff);
            if (it != st.end())
                return {*it, x};
        }

        return {0, 0};
    }
};