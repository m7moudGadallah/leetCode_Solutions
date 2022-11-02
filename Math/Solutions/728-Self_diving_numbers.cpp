#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    inline bool isDivisible(const int &n, const int &d)
    {
        return d and (n % d == 0);
    }

    inline bool isSelfDividing(const int &n)
    {
        int m{n};

        while (m)
        {
            if (!isDivisible(n, m % 10))
                return false;
            
            m /= 10;
        }

        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> ans;

        for (int i = left; i <= right; ++i)
            if (isSelfDividing(i))
                ans.emplace_back(i);
        
        return ans;
    }
};