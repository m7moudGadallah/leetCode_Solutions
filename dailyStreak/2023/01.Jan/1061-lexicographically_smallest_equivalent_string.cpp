/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> ds;     //disjoint set

    int find(int v) {
        if (ds[v] == -1)        return v;       //it means it's an absolute root of set
        return find(ds[v]);     //keep searching about it's absolute root
    }

    void unionOp(int child, int parent) {
        child = find(child);            //find absolute root of child
        parent = find(parent);          //find absolute root of parent
        
        //if child == parent it means that they have the same absolute so that's means we don't need to uion them becuase they already in the same set
        if (child == parent)        return;

        //we need forever the absolute root of each set to be min item in set so  on each step we check if parent is min or not
        if (child < parent)
            swap(child, parent);
        
        ds[child] = parent;     //on each child we insert it's parent
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        ds.resize(26, -1);

        for (int i = 0; i < n; ++i)
            unionOp(s1[i]-'a', s2[i]-'a');
        
        for (auto &x : baseStr)
            x = find(x-'a')+'a';        //finding absolute root of x becuase absolute root will be the min item in set which x in it
        
        return baseStr;
    }
};