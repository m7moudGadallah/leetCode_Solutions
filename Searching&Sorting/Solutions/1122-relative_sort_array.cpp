#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,  int> freq;

        for (const auto &x : arr1)
            freq[x]++;
        
        vector<int> ans((int) arr1.size());
        int indx{0};

        for (const auto &x : arr2)
        {
            while (freq[x])
                ans[indx++] = x, freq[x]--;
            
            freq.erase(x);
        }

        auto it = freq.begin();

        while (it != freq.end())
        {
            while (it->second)
                ans[indx++] = it->first, --(it->second);
            
            ++it;
        }

        return ans;
    }
};