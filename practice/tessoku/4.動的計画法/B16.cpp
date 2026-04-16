#include <bits/stdc++.h>
using namespace std;

int n, h[100009];
int dp[100009];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];

    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);
    for (int i = 3; i <= n; i++) {
        int one = abs(h[i] - h[i-1]) + dp[i-1];
        int two = abs(h[i] - h[i-2]) + dp[i-2];
        dp[i] = min(one, two);
    }

    cout << dp[n] << endl;
}