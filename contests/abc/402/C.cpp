#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> k(m);
    vector<vector<ll>> a(m);
    vector<ll> b(n);
    rep(i, m) {
        cin >> k[i];
        a[i].resize(k[i]);
        rep(j, k[i]) {
            cin >> a[i][j];
        }
    }
    rep(i, n) {
        cin >> b[i];
    }

    map<ll, ll> mp;
    rep(i, n) {
        mp[b[i]] = i;
    }

    vector<ll> cnt(n);
    vector<ll> last(m);

    rep(i, m) {
        rep(j, k[i]) {
            last[i] = max(last[i], mp[a[i][j]]);
        }
    }

    rep(i, m) {
        cnt[last[i]]++;
    }

    ll ans = 0;
    rep(i, n) {
        ans += cnt[i];
        cout << ans << endl;
    }
    return 0;
}