#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    map<char, int8_t> mp;
    inline bool check(const string &word)
    {
        int8_t row = mp[tolower(word.front())];

        for (const auto &x : word)
            if (mp[tolower(x)] != row)
                return false;
        
        return true;
    }
public:
    Solution() //empty constructor
    {
        for (auto &x : "qwertyuiop")
            mp[x] = 1;
        
        for (auto &x : "asdfghjkl")
            mp[x] =  2;
        
        for (auto &x : "zxcvbnm")
            mp[x] = 3;
    }
    vector<string> findWords(vector<string>& words) {
        
        vector<string> ans;

        for (const auto &word : words)
            if (check(word))
                ans.emplace_back(word);
        
        return ans;
    }
};