#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    inline int offest(const int &actual ,const int &correct)
    {
        return actual - correct;
    }
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = (int) arr.size();
        int l {0}, r{n - 1}, mid{0}, ans{-1};

        while (l <= r)
        {
            mid = l + (r - l) / 2;
        
            if (mid == 0 or offest(arr[mid - 1], mid) < k)
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }

        if (ans == n - 1 and ans + k >= arr.back())
            return ans + k + 1;

        return ans + k;
    }
};