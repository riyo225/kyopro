#include <bits/stdc++.h>
using namespace std;

int n;
int a[2009], d[2009];
int DP[2009][2009], dp[2009][2009];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        DP[n][i] = a[i];
        dp[n][i] = a[i];
    }

    for (int i = n-1; i >= 2; i--) {
        for (int j = 1; j <= i; j++) {
            DP[i][j] = max(DP[i+1][j], DP[i+1][j+1]);
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            if (DP[i][d[i-1]] >= DP[i][d[i-1]+1]) d[i] = d[i-1];
            else d[i] = d[i-1] + 1;
        }
        else {
            if (dp[i][d[i-1]] >= dp[i][d[i-1]+1]) d[i] = d[i-1] + 1;
            else d[i] = d[i-1];
        }
    }
    cout << a[d[n]] << endl;
    return 0;
}