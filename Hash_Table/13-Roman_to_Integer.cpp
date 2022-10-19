#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    map<char, int> mp{{'I', 1}, {'V', 5}, 
                                {'X', 10}, {'L', 50},
                                {'C', 100}, {'D', 500},
                                {'M', 1000}};
    inline bool isGreater(const char &x, const char &y)
    {
        return mp[x] > mp[y];
    }
public:
    int romanToInt(string s) {

        int ans{mp[s[0]]}, n{(int) s.size()};

        for (int i = 1; i < n; ++i)
        {
            if (isGreater(s[i], s[i - 1]))
                ans += mp[s[i]] - mp[s[i - 1]] * 2;
            else
                ans += mp[s[i]];
        }
        

        return ans;
    }
};