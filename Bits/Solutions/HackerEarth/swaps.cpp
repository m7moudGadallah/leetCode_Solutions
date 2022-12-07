#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;          cin >> n;
    vector<int> v(n);

    for (auto &x : v)
        cin >> x;

    sort(v.begin(), v.end());
    
    for (auto &x : v)
        cout << x << ' ';
    cout << '\n';
}

int main() {
    int t;          cin >> t;

    while (t--)
        solve();
}