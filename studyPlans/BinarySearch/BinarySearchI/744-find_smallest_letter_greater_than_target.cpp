/*
    Author: Mahmoud Gadallah
    LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto ans = upper_bound(letters.begin(), letters.end(), target);

        return (ans == letters.end()) ? letters[0] : *ans;     
    }
};