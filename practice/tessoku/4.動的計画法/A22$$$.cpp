#include <bits/stdc++.h>
using namespace std;

int n;
int a[100009], b[100009];
int dp[100009];

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) dp[i] = -1000000000; // なぜdp[i] = 0でやるとwaが出るのか
    // numeric_limits<int>::min()
    dp[1] = 0; 
    for (int i = 1; i < n; i++) {
        dp[a[i]] = max(dp[i] + 100, dp[a[i]]);
        dp[b[i]] = max(dp[i] + 150, dp[b[i]]);
    }

    cout << dp[n] << endl;
    return 0;
}