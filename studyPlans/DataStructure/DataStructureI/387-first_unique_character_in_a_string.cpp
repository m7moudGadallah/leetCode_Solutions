/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/**
 * # Intuition
 * - How to know the charcater is already distinct by counting chars on this word if the this frequency of this char is only 1 then it's distinct

 * # Approach
 * so we create vector with size 26 because alphabetic contains 26 char
 * then we count every char (x-'a') this will give index to array as example:
 * `a` it's indx will be `0`
 * `b` it's indx will be `1` and so on...

 * after that we iterate over string and find first char that frequency is already 1 

 * # Complexity
 * - Time complexity:
 *       O(N)

 * - Space complexity:
 *   O(M)  where M = 26
*/


class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();  
        vector<int> freq(26);       //frequency of characters

        for (auto &x : s)
            freq[x-'a']++;
        
        for (int i = 0; i < n; ++i)
            if (freq[s[i]-'a'] == 1)    return i;
        
        return -1;
    }
};