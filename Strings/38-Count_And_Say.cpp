#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
void countAndSayAux(string &s)
{
    string t{""};

    char ch = s.front();
    int cnt = 0;

    for (const auto &x : s)
    {
        if (x != ch)
        {
            t += to_string(cnt);
            t.push_back(ch);

            cnt = 0;
            ch = x;
        }

        ++cnt;
    }

    t += to_string(cnt);
    t.push_back(ch);

    s = t;
}
public:
    string countAndSay(int n) {
        string ans{"1"};

        while (--n)
            countAndSayAux(ans);
        
        return ans;
    }
};