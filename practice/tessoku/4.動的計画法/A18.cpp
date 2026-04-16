#include <bits/stdc++.h>
using namespace std;

int n, s, a[69];
bool dp[69][10009];

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) dp[i][j] = false;
    }

    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
             if (dp[i-1][j]) {
                dp[i][j] = true;
                if (j+a[i] <= s) dp[i][j+a[i]] = true;
             }
        }
    }

    if (dp[n][s]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}