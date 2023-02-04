/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        vector<int> freq1(26), freq2(26);       //freq1 ==> frequency of chars in s1          freq2 ==> frequency of chars in s2

        for (auto &x : s1)      freq1[x-'a']++;         //store freq1

        int p = -1, cnt = 0;            // p ==> point to the start of the substring of s2                   cnt ==> count of chars in the curr substring

        for (int i  = 0; i < m; ++i) {
            int x = s2[i]-'a';          //convert chars to int a,b,c, ..... ==> 0, 1, 2,.....

            if (freq1[x]) {             //if this char included in s1
                if (p == -1)  p = i;    // if we don't have a substring yet so we will intilaize pointer 

                ++freq2[x], ++cnt;

                while (freq2[x] > freq1[x])         //if we have chars more than in the s1 so we need to delete it 
                    --freq2[s2[p]-'a'], --cnt, ++p;
            }
            else {
                for (auto &x : freq2)       x = 0;      //here we clear freq2
                p = -1, cnt = 0;
            }

            if (cnt == n)       return true;
        }
        
        return cnt == n;
    }
};