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
    ll n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll ans = 0;
    rep(i, n) {
        ll a = h[i] / 5;
        ll b = h[i] % 5;
        if (b >= 3) b = 3;
        ans += 3 * a + b;
    }
    cout << ans+1 << endl;
    
    return 0;
}