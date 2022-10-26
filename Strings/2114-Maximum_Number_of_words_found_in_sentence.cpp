#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx = INT_MIN;

        for (const auto &sentence : sentences)
        {
            int cnt{0};

            for (const auto& ch : sentence)
                if (ch == ' ')
                    ++cnt;
            
            mx = max(mx, cnt + 1);
        }
        

        return mx;
    }
};