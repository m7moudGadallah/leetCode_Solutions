#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> arr;
    int d;

    inline bool binSerach(int &target) {
        int l = 0, r = arr.size() - 1, mid = 0;

        while (l <= r) {
            mid = l + ((r-l)>>2);

            int tmp = abs(arr[mid]-target);
            if (tmp <= d)
                return true;
            else if (arr[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        this->arr = arr2;
        this->d = d;

        int cnt = 0;

        for (auto &x : arr1)
            cnt += !binSerach(x);

        return cnt;     
    }
};