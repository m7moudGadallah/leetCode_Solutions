#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        int n = (int) candyType.size();

        unordered_set<int> candies;

        for (const auto &candy : candyType)
            candies.insert(candy);

        n /= 2;

        return (candies.size() > n) ? n : candies.size();      
    }
};