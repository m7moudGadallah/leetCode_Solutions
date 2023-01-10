/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (auto &x : arr) {
            freq[x]++;

            if (!x) {
                if (freq[x] > 1)      return true;
                else continue;
            }

            if (freq.count(x*2))       return true;

            if (!(x&1) and freq.count(x/2))        return true;
        }
            
        return false;
    }
};