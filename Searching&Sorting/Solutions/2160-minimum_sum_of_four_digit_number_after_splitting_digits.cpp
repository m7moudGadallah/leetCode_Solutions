#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);

        sort(s.begin(), s.end());
        
        string new1{s[0], s[3]}, new2{s[1], s[2]};

        return stoi(new1) + stoi(new2);
    }
};