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
    bool flag = false;
    int n, x; cin >> n >> x;
    vector<int> a(n-1);
    rep(i, n-1) cin >> a[i];

    sort(all(a));

    int up, dow, mid, sum;
    rep(i, n) sum+=a[i];

    up = sum - a[0];
    dow = sum - a[n-2];
    mid = sum - a[0] - a[n-2];
    int ans = 0;
    
    if (up == x) cout << a[n-2] << endl;

    else if (dow == x) cout << a[0] << endl;

    
    else if (mid == x) {
        ans = x - sum;
        if (ans >= a[0] && ans <= a[n-2]) {
            cout << ans << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    cout << mid << " " << x << endl;
}