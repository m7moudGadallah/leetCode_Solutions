#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n{(int) digits.size()};
        short sum{0}, carry{1};

        for (int i = n - 1; i >= 0; --i)
        {
            sum = digits[i] + carry;

            digits[i] = sum % 10, sum /= 10, carry = sum % 10; 

            if (!carry)
                return digits;
        }

        if (carry)
            digits.insert(digits.begin(), carry);
            
        return digits;
    }
};