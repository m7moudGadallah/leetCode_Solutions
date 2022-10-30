#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        map<bool, short> std;

        for (const auto &x : students)
            std[x]++;
        
        for (const auto &x : sandwiches)
        {
            if (std[x])
                std[x]--;
            else
                break;
        }

        return std[0] + std[1];
    }
};