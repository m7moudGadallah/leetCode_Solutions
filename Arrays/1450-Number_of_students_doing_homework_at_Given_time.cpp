#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check (int &s, int &e, int& q)
    {
        return (q >= s and q <= e);
    }
    
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        
        int cnt{0};
        
        for (int i = 0; i < (int) startTime.size(); ++i)
            if (check(startTime[i], endTime[i], queryTime))
                    ++cnt;
        return cnt;
    }
};