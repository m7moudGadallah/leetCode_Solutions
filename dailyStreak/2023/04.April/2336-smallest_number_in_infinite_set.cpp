/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/

#include<bits/stdc++.h>

using namespace std;

class SmallestInfiniteSet {
private:
    unordered_set<int> removedNums;
    int minNum;
public:
    SmallestInfiniteSet() {
        minNum = 1;
    }
    
    int popSmallest() {
        removedNums.insert(minNum);

        int popedNum = minNum;

        while (removedNums.count(++minNum));

        return (popedNum);
    }
    
    void addBack(int num) {
        removedNums.erase(num);

        minNum = min(minNum, num);
    }
};