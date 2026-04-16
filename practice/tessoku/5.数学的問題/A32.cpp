#include <bits/stdc++.h>
using namespace std;

int n, a, b;
bool dp[100009];

int main() {
    cin >> n >> a >> b;

    for (int i = 0; i <= min(a, b)-1; i++) dp[i] = false;
    for (int i = 0; i <= n; i++) {
        if (i >= a) {
            if (i >= b) {
                if (dp[i-a] && dp[i-b]) dp[i] = false;
            }
            else {
                if (dp[i-a]) dp[i] = false;
            }
        }
        else if (i >= b) {
            if (i < a) {
                if (dp[i-b]) dp[i] = false;
            }
        }
        if (!dp[i]) {
            if (i+a <= n) dp[i+a] = true;
            if (i+b <= n) dp[i+b] = true;
        }
    }

    if (dp[n]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}