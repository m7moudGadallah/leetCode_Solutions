#include <bits/stdc++.h>

using namespace std;

class RecentCounter {
private:
    queue<int> calls;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        calls.push(t);

        while (calls.front() < t - 3000)
            calls.pop();
        
        return (int) calls.size();
    }
};
