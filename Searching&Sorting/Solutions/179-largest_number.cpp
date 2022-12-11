#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n = (int) nums.size();
        
        if (n == 0)
            return "";

        vector<string> v(n);

        for (int i = 0; i < n; ++i)
            v[i] = to_string(nums[i]);
        
        sort(v.begin(), v.end(), [&] (string s1, string s2)
        {
            return s1 + s2 > s2 + s1;
        });

        string ans{""};

        for (int i = 0; i < n; ++i)
            ans += v[i];

        return (ans.front() == '0') ? "0" : ans;
    }
};