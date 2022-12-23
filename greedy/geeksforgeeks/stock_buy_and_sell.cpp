#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        int l = 0, r = 0;
        vector<vector<int>> ans;

        while (r < n-1) {
            if (A[r+1] < A[r]) {
                if (l < r)
                    ans.emplace_back(vector<int>({l, r}));
                l = r+1;
            }
            ++r;
        }

        if (l < r)
            ans.emplace_back(vector<int>({l, r}));

        return ans;
    }
};