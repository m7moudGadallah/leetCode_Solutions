#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        vector<int> freq(26);
        vector<bool> token(26, false);

        for (const auto &c : s)
            freq[c-'a']++;
        
        stack<char> stk;

        for (const auto &c : s) {
            if (token[c-'a']) {
                freq[c-'a']--;
                continue;
            }

            while (!stk.empty() and stk.top() > c and freq[stk.top()-'a'])
                token[stk.top()-'a'] = false,stk.pop();
            
            stk.push(c);
            freq[c-'a']--;
            token[c-'a'] = true;
        }

        string ans{""};
        while (!stk.empty())
            ans += stk.top(), stk.pop();
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};