/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

/**
 * Approach:
 *         any IP Address can be formed as xxx.xxx.xxx.xxx so max lenght for s would be 12 otherwise we can't form an ip address
 *         
 *          [1] ok now we now on each part of Ip address can be x or xx or xxx so we will brute force and try all cases 
 *          so what is the states we care about it?
 *              - idx  ==> current index we use to iterate over string s
 *              - numofdots => because we need to know if we reach 4 dots so now it's okay we create Ip address
 *              - currIp ==> this IP accully we will create it
 *          
 *          so back to [1] we will take substrs of sizes 1, 2, 3 so we use `j` to generate sizes and then we get substr and assign it to `sub`
 *          now we check it's valid or not, how we do that?
 *              - we know ip address can't be lead a zeros okay we check if first element on sub is zero so it's not valid but we have only one case is vaild `0.x.x.x` if already we have some part of ip address only have a zero
 *              - if current sub is greater than 255 also it's not valid 
*/

class Solution {
private:
    string str;
    vector<string> validIps;
    void validIp(int idx, int numOfdots, string currIP) {
        if (idx == str.size() and numOfdots == 4) {
            currIP.pop_back();
            validIps.emplace_back(currIP);
            return;
        }

        if (numOfdots >= 4)     return;

        for (int j = 0; j < min(3, (int)str.size() - idx); ++j) {
            string sub = str.substr(idx, j+1);

            if (sub.front() == '0' && j != 0)
                break;

            if (stoi(sub) <= 255)
                validIp(idx+j+1, numOfdots+1, currIP+sub+".");
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        this->str = s;
        
        if (s.size() > 12)      return validIps;
        validIp(0, 0, "");
        return validIps;
    }
};