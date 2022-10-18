#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        int n{(int) list1.size()}, m{(int) list2.size()};

        unordered_map<string, int> mp;               //map to store (items of list2, first apperatance)

        for (int i = 0; i < m; ++i)
            if (!mp.count(list2[i]))
                mp[list2[i]] = i;
        
        vector<string> ans;         //vector of answers
        
        int least_sum{INT_MAX};

        for (int i = 0; i < n; ++i)
        {
            if (mp.count(list1[i]))
            {
                int sum{mp[list1[i]] + i};

                if (sum > least_sum)
                    continue;
                    
                if (sum < least_sum)
                    least_sum = sum, ans.clear();
                
                ans.emplace_back(list1[i]);
            }

        }
        
        return ans;        
    }
};