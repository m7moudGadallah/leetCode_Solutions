/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    /**
     * @name conv2Char
     * @brief use this function to convert int to vector of char that contains it's digits 
     * @pre nothing
     * @post Convert int to vector of char
     * @param n number want to convert it
     * @return vector<char> vector contains digits of number
     */
    vector<char> conv2Char(int n) {
        if (n < 2)
            return {};
        string str = to_string(n);
        vector<char> ans(str.begin(), str.end());
        return ans;
    }
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), cnt = 1;
        vector<char> ans {chars.front()};

        for (int i = 1; i < n; ++i) {
            if (chars[i] == ans.back())
                ++cnt;
            else {
                vector<char> digits = conv2Char(cnt);
                ans.insert(ans.end(),digits.begin(), digits.end());
                ans.emplace_back(chars[i]);
                cnt = 1;
            }
        }

        vector<char> digits = conv2Char(cnt);
        ans.insert(ans.end(),digits.begin(), digits.end());

        chars = ans;

        return ans.size();
    }
};