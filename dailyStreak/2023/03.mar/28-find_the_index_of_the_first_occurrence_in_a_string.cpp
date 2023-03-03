/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/**
 * @brief problem explanation
 * @link https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/3252015/simple-c-solution-beats-100/
 */


class Solution {
private:
    inline bool isSubStr(const string &s, const string &t, int idx) {
        int n = s.size(), m = t.size();

        if (n-idx < m)
            return false;

        for (int i = 0; i < m; ++i) {
            if (idx >= n or s[idx++] != t[i])
                return false;
        }

        return true;
    }
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();

        if (n < m)
            return -1;
        
        for (int i = 0; i < n; ++i) {
            if (isSubStr(haystack, needle, i))
                return i;
        }

        return -1;
    }
};