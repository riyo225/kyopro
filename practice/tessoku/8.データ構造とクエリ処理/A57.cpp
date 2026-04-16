#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[100009], x[100009], y[100009];
int dp[30][100009];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= q; i++) cin >> x[i] >> y[i];

    for (int i = 1; i <= n; i++) dp[0][i] = a[i];

    for (int i = 1; i <= 29; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }

    for (int i = 1; i <= q; i++) {
        
    }
    return 0;
}