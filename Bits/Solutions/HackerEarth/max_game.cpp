#include<bits/stdc++.h>
using namespace std;

int solve (int N) {
   // Write your code here
   int cnt{0};

   while (N)
    N >>= 1, ++cnt;

    return (1 << (cnt - 1));
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;

        int out_;
        out_ = solve(N);
        cout << out_;
        cout << "\n";
    }
}