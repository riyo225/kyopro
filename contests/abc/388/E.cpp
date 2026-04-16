#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
// sortmacro
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define GT greater<int>()
// priority_queue
#define VG vector<int>, greater<int>

// variables
ll n;
ll a[500009];
ll ans = 0;
ll x = n / 2;

int main() {
    cin >> n;
    rrep(i, n) cin >> a[i];

    ll x = n / 2;
    for (int i = n; i >= 0; i--) {
        ll pos = upper_bound(a+1, a+x+1, a[i]/2) - a;
        // cout << a[pos-1] << endl;
        // cout << pos-1 << endl;
        // cout << "--------" << endl;
        if (pos-1 > 0) {
            ans++;
            x = pos - 2;
        }
    }
    cout << ans << endl;

    return 0;
}