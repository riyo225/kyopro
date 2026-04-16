#include <bits/stdc++.h>
using namespace std;

string s, t;
int dp[2009][2009];

int main() {
    cin >> s >> t;
    int sS = s.size();
    int tS = t.size();
    for (int i = 0; i <= sS; i++) {
        for (int j = 0; j <= sS; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= sS; i++) {
        for (int j = 1; j <= tS; j++) {
            if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[sS][tS] << endl;
}