#include <bits/stdc++.h>
using namespace std;

int n, ans;
long long W;
int w[109], v[109];
long long dp[109][100009];

int main() {
    cin >> n >> W;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 100009; j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 100009; j++) {
            if (dp[i-1][j] != -1) {
                dp[i][j] = dp[i-1][j];
                if (dp[i-1][j] + w[i] <= W) dp[i][j+v[i]] = dp[i-1][j] + w[i];
            }
        }
    }

    ans = 0;
    for (int j = 0; j < 100009; j++) {
        if (dp[n][j] != -1) ans = max(ans, j);
    }

    cout << ans << endl;
    return 0;
}