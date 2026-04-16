#include <bits/stdc++.h>
using namespace std;

int h, w;
char c[39][39];
long long dp[39][39];

int main() {
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> c[i][j];
            dp[i][j] = 0;
        }
    }

    dp[1][1] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (c[i][j] != '#') {
                if (c[i+1][j] != '#') dp[i+1][j] += dp[i][j];
                if (c[i][j+1] != '#') dp[i][j+1] += dp[i][j];
            }
        }
    }

    cout << dp[h][w] << endl;
    return 0;
}