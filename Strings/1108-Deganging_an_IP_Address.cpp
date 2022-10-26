#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        
        string defang{""};

        for (const auto &ch : address)
        {
            if (ch == '.')
                defang += "[.]";
            else
                defang.push_back(ch);
        }

        return defang;
    }
};