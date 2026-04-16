#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Yes(b) ((b)?"Yes":"No")
#define YES(b) ((b)?"YES":"NO")
using vi = vector<int>;

signed main() {
    int n; cin >> n;
    vi(a);
    rep(i, n) cin >> a[i];

    sort(all(a));

    int ans = a[0]-1;
    rep(i, n-1) {
        if (a[i+1] != a[i] + 1) {
            ans = a[i+1];
            break;
        }
    }
    cout << ans << endl;
}