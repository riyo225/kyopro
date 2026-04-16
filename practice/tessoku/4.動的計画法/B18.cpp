#include <bits/stdc++.h>
using namespace std;

int n, s, a[69];
int dp[69][10009];
vector<int> ans;

int main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) dp[i][j] = -1;
    }
    
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (dp[i-1][j] != -1) {
                dp[i][j] = dp[i-1][j];
                if (j+a[i] <= s) dp[i][j+a[i]] = dp[i-1][j] + a[i];
            }
        }
    }

    if (dp[n][s] == s) {
        int i = n;
        int sum = s;
        while (sum > 0) {
            if (dp[i][sum] != dp[i-1][sum]) {
                sum -= a[i];
                ans.push_back(i);
            }
            i--;
        }

        sort(ans.begin(), ans.end());

        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }
    else cout << -1 << endl;
    return 0;
}