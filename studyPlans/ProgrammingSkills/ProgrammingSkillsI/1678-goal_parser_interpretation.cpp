#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string interpret(string command) {
        int n = command.size();

        string ans = "";

        for (int i = 0; i < n; ++i) {
            if (command[i] == '(') {
                if (command[i+1] == ')')
                    ans += 'o', ++i;
                else
                    ans+= "al", i += 3;
            }
            else
                ans += command[i];
        }

        return ans;
    }
};