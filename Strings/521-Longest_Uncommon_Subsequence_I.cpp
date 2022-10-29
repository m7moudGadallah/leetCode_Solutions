#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {

        return (a != b) ? max<int>(a.size(), b.size()) : -1;
    }
};