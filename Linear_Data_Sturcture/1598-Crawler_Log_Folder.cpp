#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {

        int depth = 0;

        for (const auto &log : logs)
        {
            if (log == "./")
                continue;
            
            if (log == "../")
                depth = (depth <= 0) ? 0 : depth - 1;
            else
                ++depth;
        }

        return depth;
    }
};