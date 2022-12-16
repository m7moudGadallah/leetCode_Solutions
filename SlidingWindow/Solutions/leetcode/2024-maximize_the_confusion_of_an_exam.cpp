#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int l = 0, r = 0;
        int cntOnes =0, cntZeors = 0, mx = 0;

        while (r < n) {
            cntOnes += (answerKey[r]=='T');
            cntZeors += (answerKey[r]=='F');

            if (cntOnes <= k or cntZeors <= k) {
                mx = max(mx, (r-l + 1));
            }
            else {
                cntOnes -= (answerKey[l]=='T');
                cntZeors -= (answerKey[l]=='F');
                ++l;
            }

            ++r;
        }

        return mx;
    }
};