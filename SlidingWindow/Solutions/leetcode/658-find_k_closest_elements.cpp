#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int len(int l, int r) {
        return r - l + 1;
    }
    
    int diff(int x, int y) {
        return abs(x - y);
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k >= arr.size())
            return arr;
        
        int l = 0, r = arr.size() - 1;

        while (len(l, r) > k) {
            if (diff(arr[l], x) > diff(arr[r], x))
                ++l;
            else
                --r;
        }

        vector<int> ans(k);
        for (auto &x : ans)
            x = arr[l++];
        
        return ans;
    }
};