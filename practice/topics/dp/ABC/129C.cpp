#include <bits/stdc++.h>
using namespace std;
#define int long long
long long a[100010];
long long dp[100010];

signed main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // 初期化
    for (int i = 0; i < 100010; i++) dp[i] = 0;
    // ベースケース
    dp[0] = 0;
    if (a[0] != 1) dp[1] = 1;
    if (a[0] == 1 && a[1] != 2) dp[2] = 1;
    if (a[0] != 2 || a[1] != 2) dp[2] = 2;
    
    int w = 0;
    for (int i = 3; i <= n; i++) {
        if (i != a[w]) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        else {
            w++;
            continue;
        }
    }
    cout << dp[n] % 1000000007 << endl;
}