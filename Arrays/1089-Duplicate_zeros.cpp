#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int sz = (int) arr.size();
        
        vector<int> v(sz);
        
        int i = 0, j = 0;
        
        while (i < sz and j < sz)
        {
            v[i++] = arr[j];
            
            if (!arr[j] and i < sz)
                    v[i++] = 0;
            ++j;
        }    
        
        arr= v;
    }
};