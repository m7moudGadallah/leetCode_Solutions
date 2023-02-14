/**
 *  Author: Mahmoud Gadallah
 *  LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    int carry;
    string res;
    void add(int x = 0, int y = 0) {
        res = ((x^y^carry) ? "1" : "0") + res;
        carry = (x&y) | ((x^y) & carry);
    }
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();

        while (n and m)
            add(a[--n]-'0', b[--m]-'0');
        
        while (n)
            add(a[--n]-'0');
        
        while (m)
            add(b[--m]-'0');
        
        return (carry) ? "1"+res : res;
    }
};