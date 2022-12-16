#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int remove_duplicate(int a[],int n){
        // code here
        int cnt = 1;

        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1])
                continue;
            
            a[cnt] = a[i];
            ++cnt;
        }

        return cnt;
    }
};