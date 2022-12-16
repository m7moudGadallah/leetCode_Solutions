#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        unordered_set<int> found;
        
        for (int i = 0; i < n; ++i) {
            found.insert(a[i]);
        }
        
        int cnt = 0;
        
        for (int i = 0; i < m; ++i) {
            if (found.count(b[i])) {
                ++cnt;
                found.erase(b[i]);
            }    
        }
        
        return cnt;
    }
};