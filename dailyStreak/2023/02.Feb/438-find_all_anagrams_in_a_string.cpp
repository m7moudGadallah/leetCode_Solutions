/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

// # Intuition
// what is angrams is 2 strings they have the same chars with same or different orders
// ex: `abc` is angram of `cba` also is angram of `bca`
// so what is the simple way to know angrams with  `hash table`

// # Approach
// at first we need to `hash` cahrs of `p` to compare other strings with it to know if it angram or not

// secondly we need to hash another string and if they have the same chars so they are angram

// so point to the start of the string and find if this char is already include in `p` or not if it includes and we don't have string yet so we make `it` to point to current postions

// if we find an char is not in p so it's impossible that current string to be angram of `p` so we will `clear` hash table of substring `freq2`

// and keep doing this process at some point if `cnt` *number of chars of current substring* is equal to `p.size()` so we find `angram` so we will push `it` and then move `it` one step forward to get a new substring

// # Complexity
// - Time complexity:
// o(n*d) when `n` is `s.size()` and `d` is number of deletation

// - Space complexity:
// O(n)  when `n` is `26 + 26` size of `freq1` `freq2`

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();

        vector<int> freq1(26), freq2(26), ans;

        for (auto &x : p)       ++freq1[x-'a'];

        int it = -1, cnt = 0;

        for (int i = 0; i < n; ++i) {
            int x = s[i]-'a';

            if (freq1[x]) {
                if (!cnt)     it = i;
                ++freq2[x], ++cnt;
                
                while (freq2[x] > freq1[x])
                    --freq2[s[it]-'a'], --cnt, ++it;
            }
            else {
                for (auto &x : freq2)       x = 0;
                it = -1, cnt = 0;
            }

            if (cnt == m) {
                ans.emplace_back(it);
                --freq2[s[it]-'a'], --cnt, ++it;
            }
        }

        return ans;
    }
};