#include <bits/stdc++.h>

using namespace std;

class Solution 
{
    public:
        string licenseKeyFormatting(string s, int k) 
        {
            int n = (int) s.size();

            int cnt{0};
            string ans{""};

            for (int i = n - 1; i >= 0; --i)
            {
                if (s[i] == '-')
                    continue;
                
                if (s[i] >= 'a' and s[i] <= 'z')
                    s[i] = toupper(s[i]);

                ans.push_back(s[i]);
                ++cnt;

                if (cnt >= k)
                    ans.push_back('-'), cnt = 0;
            }

            if (ans.back() == '-')
                ans.pop_back();
            
            reverse(ans.begin(), ans.end());

            return ans;
        }
};