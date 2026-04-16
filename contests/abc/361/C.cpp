#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

signed main() {
    int k, n;
    int ans;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());
    ans = a[n-1];
    rep(i, k+1) {
        int sub = a[i+n-k-1] - a[i];
        ans = min(ans, sub);
    }
    cout << ans << endl;
}