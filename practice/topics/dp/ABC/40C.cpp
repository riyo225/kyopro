#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

long long h[100010];
long long dp[100010];

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < 100010; i++) dp[i] = INF;

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        chmin(dp[i], abs(a[i] - a[i-1]) + dp[i-1]);
        if (i != 1) chmin(dp[i], abs(a[i] - a[i-2]) + dp[i-2]);
    }

    cout << dp[n-1] << endl;    
}