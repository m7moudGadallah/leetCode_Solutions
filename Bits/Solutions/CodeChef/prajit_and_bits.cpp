#include <bits/stdc++.h>
 
//definitions
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define TC int t; cin >> t; while (t--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define cout(v) for (auto &x : v) cout << x << ' ';
#define cin(v)  for (auto &x : v) cin >> x;
#define ccin(v, state) for (auto &x : v) {cin >> x;  state;}
#define prefix(v, n) for (int i = 1; i < n; i++) v[i] += v[i - 1];
#define eps 1e-7
#define oo (int) 1e9
 
using namespace std;
 
 
//function declearation
inline void in_out();
inline void solve();
 
int main() {
    in_out();
 
    TC
    solve();        //solution here
 
    return 0;
}
 
 
 
//*******************************************************functions************************************************************
 
//          **in_out**
inline void in_out() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif  
}


inline int countBits0(int n) {
    int cnt{0};
    
    while (n) {
        cnt += !(n&1);
        n >>= 1;
    }

    return cnt;
}
 
//          **solve**
inline void solve() {
    int n;      cin >> n;
    cout << countBits0(n) << '\n';
}