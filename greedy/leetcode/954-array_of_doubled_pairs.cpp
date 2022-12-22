#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        sort(arr.begin(), arr.end());

        for (auto &x : arr)
            freq[x]++;
        
        for (auto &x : arr) {
            if (freq.count(2*x) and freq[x] and freq[2*x]) {
                --freq[x];
                --freq[2*x];
            }
        }

        for (auto x : freq)
            if (x.second)
                return false;
        
        return true;
    }
};