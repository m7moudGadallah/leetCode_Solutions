/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    void fillBiggestStones(vector<int>& stones, priority_queue<int> &biggestStones) {
        for (auto stone : stones)
            biggestStones.push(stone);
    }

    int smash(int stoneX, int stoneY) {
        return (stoneX - stoneY);
    }
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> biggestStones;

        fillBiggestStones(stones, biggestStones);

        while (biggestStones.size() > 1) {
            int stoneX = biggestStones.top();
            biggestStones.pop();

            int stoneY = biggestStones.top();
            biggestStones.pop();

            biggestStones.push(smash(stoneX, stoneY));
        }

        return (biggestStones.top());
    }
};