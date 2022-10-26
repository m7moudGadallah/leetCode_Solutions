#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = (int) num1.size() - 1, j = (int) num2.size() - 1;
        int c{0};           //carry of sum operation
        string ans{""};

        while (i >= 0 and j >= 0)
        {
            int sum = num1[i--] - '0' + num2[j--] - '0' + c;
            c = sum / 10;

            ans = to_string(sum % 10) + ans;
        }

        while (i >= 0)
        {
            int sum = num1[i--] - '0' + c;
            c = sum / 10;

            ans = to_string(sum % 10) + ans;
        }

        while (j >= 0)
        {
            int sum = num2[j--] - '0' + c;
            c = sum / 10;
            
            ans = to_string(sum % 10) + ans;
        }

        if (c)
            ans = to_string(c) + ans;
        
        return (ans.empty()) ? "0" : ans;
    }
};