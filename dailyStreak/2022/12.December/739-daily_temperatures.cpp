#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> warmTemp;
        int n = temperatures.size();
        vector<int> answer(n);

        for (int i = n - 1; i >= 0; --i) {
            while (!warmTemp.empty() and temperatures[i] > temperatures[warmTemp.top()])
                warmTemp.pop();
            
            if (!warmTemp.empty())
                answer[i] = warmTemp.top()-i;
            
            warmTemp.push(i);
        }

        return answer;
    }
};