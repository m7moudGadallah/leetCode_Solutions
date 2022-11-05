#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans{""};

        while (columnNumber > 0) {
            columnNumber--;

            ans = char('A' + columnNumber % 26) + ans;

            columnNumber /= 26;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    obj.convertToTitle(2147483647);

    return 0;
}