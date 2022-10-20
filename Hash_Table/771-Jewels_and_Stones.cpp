#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        unordered_map<char, int> freq;      //frequency map of jewels

        for (const auto &jewel : jewels)
            freq[jewel]++;
        
        int ans{0};         //answer

        for (const auto &stone : stones)     //iterate over stones to count number of stones that is jewels
            if (freq.count(stone))
                ans += freq[stone];

        return ans;
    }
};


//another solution
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
    int ans = 0;

    for (auto c : jewels)       //iterate over jewels and count it's number in stones
        if (stones.find(c) != string :: npos)
            ans += count(stones.begin(), stones.end(), c);
    
        return ans;
    }
};