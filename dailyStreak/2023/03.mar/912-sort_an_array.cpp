/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void merge(vector<int> &arr, int l, int m, int r) {
        int n1 = m-l + 1;       //size of left parition
        int n2 = r-m;           //size fo right parition

        vector<int> arr1(n1);     //left parition;
        vector<int> arr2(n2);     //right

        int idx = 0;

        for (int i = l; i <= m; ++i) {
            arr1[idx++] = arr[i];
        }

        idx = 0;        
        for (int i = m+1; i <= r; ++i) {
            arr2[idx++] = arr[i];
        }

        idx = l;        //reset idx to l and now we use it to iterate over arr
        int idx1 = 0, idx2 = 0;     //idx1 to iterate over arr1,   idx2 to iterate over arr2
        
        while (idx1 < n1 and idx2 < n2) {
            if (arr1[idx1] < arr2[idx2])
                arr[idx++] = arr1[idx1++];
            else
                arr[idx++] = arr2[idx2++];
        }

        while (idx1 < n1)
            arr[idx++] = arr1[idx1++];
        
        while (idx2 < n2)
            arr[idx++] = arr2[idx2++];
    }
    void mergeSort(vector<int> &arr, int l , int r) {
        if (l < r) {
            int m = l + ((r-l)>>1);     //getting mid pointer

            mergeSort(arr, l, m);        //sort left partition
            mergeSort(arr, m+1, r);         //sort right partition
            merge(arr, l, m, r);            //merge left & right parition
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> arr = nums;
        if (nums.empty())
            return nums;

        mergeSort(arr, 0, arr.size()-1);
        return arr;
    }
};