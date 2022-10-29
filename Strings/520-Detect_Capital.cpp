#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = (int) word.size();
        int cap_num{0};
        
        auto is_up = [&] (const char &c) {return c >= 'A' and c <= 'Z';};

        for (const auto &ch : word)
            cap_num += is_up(ch);
        
        if (is_up(word.front()) and cap_num == 1)
            cap_num = 0;

        return !(cap_num >= 1 and cap_num < n);
    }
};