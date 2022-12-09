#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask{0}, ans{0};

        for (int i = 31; i >= 0; --i) {
            mask |= (1<<i);
            set<int> visited;

            for (auto &x : nums)
                visited.insert(x&mask);
            
            long long tmp = ans | (1<<i);

            for (auto &x : visited)
                if (visited.count((x^tmp))) {
                    ans = tmp;
                    break;
                }
        }

        return ans;
    }
};