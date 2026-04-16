#include <bits/stdc++.h>
using namespace std;

int n, h[100009];
int dp[100009];
vector<int> ans;

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

    int i = n;
    while (i > 0) {
        ans.push_back(i);
        if (dp[i] == dp[i-1] + abs(h[i] - h[i-1])) i = i-1;
        else i = i-2;
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}