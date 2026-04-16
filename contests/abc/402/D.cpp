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
    vector<ll> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = 2*i+1;
    }

    vector<pair<int, int>> vec;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        vec.push_back({a, b});
    }

    map<ll, ll> mp;

    for (auto [a, b] : vec) {
        ll x = abs(a - b) - 1 + r[min(a, b)];
        while (x > n) {
            x -= n;
        }
        while (x < 0) {
            x += n;
        }
        mp[x]++;
    }

    ll ans = vec.size()*(vec.size()-1)/2;
    for (auto [k, v] : mp) {
        ans -= v*(v-1)/2;
    }

    cout << ans << endl;    
    return 0;
}