#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    inline vector<string> split(const string &s, char delemiter)
    {
        int n = (int) s.size();

        vector<string> words;           //vector will contains words after spliting string

        int pos = s.find(delemiter), i = 0;

        while (pos != string::npos)     //iterate over string seraching for delemiter
        {
            words.emplace_back(s.substr(i, pos - i));   //cutting sub string from i to pos of delemeiter and push it to words

            i = pos + 1;    //moving i to first position after delemeiter position

            pos = s.find(delemiter, i);
        }

        words.emplace_back(s.substr(i, n - i));     //getting remaining word of string

        return words;
    }
public:
    bool wordPattern(string pattern, string s) {
        
        int n = (int) pattern.size();

        vector<string> words = split(s, ' ');   //spliting string to words

        int m = (int) words.size();

        if (n != m)         //check if pattern and words doesn't have the same size 
            return false;

        unordered_map<char, string> mp;     //maping each char in pattern with word form words
        unordered_set<string> visited;

        for (int i = 0; i < n; ++i)
        {
            if (mp.count(pattern[i]))
            {
                if (mp[pattern[i]] != words[i])
                    return false;
            }
            else
            {
                if (visited.find(words[i]) != visited.end())    //check if this word is already maped to another char or not
                    return false;

                mp[pattern[i]] = words[i];
                visited.insert(words[i]);
            }
        }

        return true;
    }
};