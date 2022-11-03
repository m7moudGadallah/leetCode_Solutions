#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    inline vector<int> splitDate(const string &data) {
        int pos = data.find('-'), i{0}, n {(int) data.size()};
        vector<int> ans;

        while (i < n and pos != string::npos) {

            ans.emplace_back(stoi(data.substr(i, pos - i)));

            i = pos + 1;
            pos = data.find('-', i);
        }

        ans.emplace_back(stoi(data.substr(i, n - i)));

        return ans;
    }

    inline bool leapYear(const int &year) {
        if (year % 400 == 0) {
            return true;
        }
        else if (year % 100 == 0) {
            return false;
        }
        else if (year % 4 == 0) {
            return true;
        }

        return false;
    }

    inline int yearDays(const int &year) {
        return leapYear(year) ? 366 : 365;
    }

    inline int monthDays(const int &month, const int &year) {
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;   break;
            case 2:
                return (leapYear(year)) ? 29 : 28;
            default:
                return 30;  break;
        }

        return 0;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        vector<int> d1 = splitDate(date1), d2 = splitDate(date2);

        if (d1[0] > d2[0])
            swap(d1, d2);

        int days{0};

        for (int i = d1[0]; i < d2[0]; ++i) {
            days += yearDays(i);
        }
        
        while (--d1[1])
            days -= monthDays(d1[1], d1[0]);
        
        while (--d2[1])
            days += monthDays(d2[1], d2[0]);
        
        days -= d1[2];
        days += d2[2];

        return abs(days);
    }
};