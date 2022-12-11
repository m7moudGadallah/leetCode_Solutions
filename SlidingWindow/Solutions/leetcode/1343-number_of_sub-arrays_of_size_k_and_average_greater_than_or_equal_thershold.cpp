#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum{accumulate(arr.begin(), arr.begin()+k, 0)}, l{0}, r{k};
        int cnt = (sum/k >= threshold), n = arr.size();
        
        while (r < n) {
            sum -= arr[l++], sum += arr[r++];
            cnt += (sum/k >= threshold);
        }

        return cnt;
    }
};