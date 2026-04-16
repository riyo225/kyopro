#include <bits/stdc++.h>
using namespace std;

int n, a[100009], b[100009], dp[100009];
vector<int> ans;

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> a[i];
    for (int i = 3; i <= n; i++) cin >> b[i];

    dp[1] = 0;
    dp[2] = a[2];
    for (int i = 3; i <= n; i++) {
        int one = dp[i-1] + a[i];
        int two = dp[i-2] + b[i];

        dp[i] = min(one, two);
    }

    int i = n;
    while (i > 0) {
        ans.push_back(i);
        if (dp[i] == dp[i-1] + a[i]) i = i-1;
        else i = i-2;
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}