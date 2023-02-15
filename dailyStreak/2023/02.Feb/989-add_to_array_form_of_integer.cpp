
/**
 *  Author: Mahmoud Gadallah
 *  LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/**
 * solution Explanation: https://leetcode.com/problems/add-to-array-form-of-integer/solutions/3187737/simple-c-solution-with-good-explanation-beats-more-than-95/
 */

class Solution {
private:
    vector<int> ans;
    int carry;
    void add(int x=0, int y=0) {
        int currSum = x + y + carry;        //adding 2 digits with last carry
        
        if (currSum > 9)        //if number is greater than 9 so we have a carry
            currSum %= 10, carry = 1;
        else
            carry = 0;
        
        ans.emplace_back(currSum);
    }
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        
        int idx = n;

        while (k and idx) {     // add digits of num to digits of k from left to right
            add(num[--idx], k%10);
            k /= 10;
        }

        while (idx) {       //if we still have digits on num so we will keep adding it with carry
            add(num[--idx]);
        }
        
        while (k) {     //if we still have digits on k so we will keep adding it with carry
            add(k%10);
            k /= 10;
        }
        
        if (carry) ans.emplace_back(1);     //if we have a carry so we add it to the end of the number
        
        //now we have the result but it represented from right to left so we need to reverse it
        reverse(ans.begin(), ans.end());
        return ans;
    }
};