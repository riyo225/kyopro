#include <bits/stdc++.h>
using namespace std;

int N, W, ans, w[109], v[109], dp[109][100009];

int main() {
    cin >> N >> W;
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) dp[i][j] = -1;
    }

    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (dp[i-1][j] != -1) {
                dp[i][j] = dp[i-1][j];
                if (j+w[i] <= W) dp[i][j+w[i]] = max(dp[i][j], dp[i-1][j] + v[i]);
            }
        }

        for (int i = 0; i <= W; i++) ans = max(ans, dp[N][i]);
        cout << ans << endl;
        return 0;
    }
}