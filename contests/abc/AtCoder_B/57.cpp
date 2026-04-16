#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(m);
    vector<ll> d(m);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, m) cin >> c[i] >> d[i];

    vector<ll> ans(n, INF);
    vector<ll> len(n, INF);
    
    rep(i, n) {
        rep(j, m) {
            ll l = abs(a[i]-c[j]) + abs(b[i]-d[j]);
            if (l < len[i]) {
                len[i] = l;
                ans[i] = j+1;
            }
            else if (l == len[i]) {
                ans[i] = min(j+1, ans[i]);
            }
        }
    }
    rep(i, n) cout << ans[i] << endl;
    return 0;
}