#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[39];
bool dp[39][10000009];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0 ; j <= k; j++) {
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[i-1][j]) {
                dp[i][j] = true;
                if (j+a[i] <= k) dp[i][j+a[i]] = true; 
            }
        }
    }

    bool ans = false;
    for (int i = 0; i <= n; i++) {
        if (dp[i][k]) {
            ans = true;
            break;
        }
    }
    
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}