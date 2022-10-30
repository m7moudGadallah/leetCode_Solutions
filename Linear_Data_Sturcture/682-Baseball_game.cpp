#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    stack<int> record;

    void operation(const string &s)
    {
        if (isdigit(s.back()))
            record.push(stoi(s));
        else
        {
            if (s == "+")
            {
                int a = record.top(); record.pop();
                int b = record.top(); record.pop();
                record.push(b), record.push(a), record.push(a + b);
            }
            else if (s == "D")
                record.push(record.top() * 2);
            else
                record.pop();
        }
    }
    
    int ans()
    {
        int sum{0};

        while (!record.empty())
            sum += record.top(), record.pop();
        
        return sum;
    }

public:
    int calPoints(vector<string>& operations) {
        
        for (const auto &oper : operations)
            operation(oper);

        return ans();
    }
};
