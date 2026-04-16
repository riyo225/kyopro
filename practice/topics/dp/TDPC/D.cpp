#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;

long long dp[1000000][110];

int n, d;

int main() {
    cin >> n >> d;
    for (int i = 0; i < INF; i++) for (int j = 0; j < n; j++) dp[i][j] = 0;

    for (int i = 0; i < 6; i++) dp[i][0] = 1;

    for (int i = 0; i < INF; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 6; k++) {
                if (dp[i][j]) {
                    dp[i*k][j+1] += dp[i][j];
                }
            }
        }
    }

    float count = 0;
    for (int i = 0; i < INF; i++) {
        count += dp[i][n-1];
    }

    for (int i = 0; i < n; i++) {
        count / 6;
    }

    cout << count << endl;


}