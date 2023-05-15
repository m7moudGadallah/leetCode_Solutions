/**
 *  @author Author: Mahmoud Gadallah
 *  @link LeetCode Account: https://leetcode.com/m7moudGadallah/
*/

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *leftPointer = head,
            *rightPointer = head,
            *leftNode = nullptr,
            *rightNode = nullptr;
        
        //get left node
        for (int nodeNumber = 1; nodeNumber < k; ++nodeNumber) {
            rightPointer = rightPointer->next;
        }

        leftNode = rightPointer;


        //get right node
        while (rightPointer->next) {
            leftPointer = leftPointer->next;
            rightPointer = rightPointer->next;
        }

        rightNode = leftPointer;


        //swap values of leftNode and rightNode
        swap(leftNode->val, rightNode->val);

        return head;
    }
};