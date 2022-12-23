#include<bits/stdc++.h>

using namespace std;

long long int maxSum(int arr[], int n)
{
    sort(arr, arr+n);
    int l = 0, r = n - 1;
    long long sum = 0;

    while (l < r) {
        sum += abs(arr[r] - arr[l++]);

        if (l < r)
            sum += abs(arr[r] - arr[l]);
        --r;
    }
    
    r += !(n&1);
    sum += arr[r] - arr[0];

    return sum;
}
