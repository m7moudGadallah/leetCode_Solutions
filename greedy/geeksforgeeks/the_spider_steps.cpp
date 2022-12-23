#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int minStep(int H, int U, int D){
        if (U==1)
            return H;
        H -= U-1;
        int ans = 1 + H / (U-D);
        int rem = H % (U-D);
        
        
        if (rem != 0 and rem <= U)
            ++ans;
        else
            ans += ceil(double(rem)/U);

        return ans;
    }
};