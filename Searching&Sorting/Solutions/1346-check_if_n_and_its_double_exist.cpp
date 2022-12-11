#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;

        for (const auto &x : arr)
            mp[x]++;
        

        for (const auto &x : arr)
        {
            if (!x)
            {
                if (mp[x] >= 2)
                    return true;
            }
            else if (mp.count(2 * x))
                return true;
        }

        return false;
    }
};