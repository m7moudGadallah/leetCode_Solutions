#include<bits/stdc++.h>

#define newLine cout << '\n';

using namespace std;

inline void solve() {
    int n;          cin >> n;
    long long a, b, ans;
    
    cin >> a >> b;
    ans = a&b;

    while (--n)
        cin >> a >> b, ans &= (a&b);
    
    cout << ans;
    newLine;
}

int main() {
    int t;          cin >> t;

    while (t--)
        solve();

    return 0;
}