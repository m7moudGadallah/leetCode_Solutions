#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int n {(int) columnTitle.size()};

        int ans{0};

        for (int i = n - 1; i >= 0; --i)
            ans += (columnTitle[i] - 'A' + 1) * pow(26, n - i - 1);

        return ans;
    }
};
