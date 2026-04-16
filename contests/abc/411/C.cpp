#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rrep(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define repbit(bit, n) for (ll bit = 0; bit < (1LL << (ll)(n)); bit++)
#define each(x, a) for (auto& x : a)
#define each2(a, b, c) for (auto& [a, b] : c)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((ll)(x).size())
#define nl "\n"
template<class T> bool chmax(T& a, const T& b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> bool chmin(T& a, const T& b) {
    if (a > b) { a = b; return true; }
    return false;
}
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1, 0, -1};
const double PI = 3.141592653589793;
struct Edge
{
    ll to;
    ll cost;
};
using Graph = vector<vector<ll>>;


int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(q);
    rep(i, q) {
        cin >> a[i];
        a[i]--;
    }
    vector<bool> f(n, false);
    ll ans = 0;
    

    rep(i, q) {
        bool l = (a[i] > 0) && f[a[i]-1];
        bool r = (a[i]+1 < n) && f[a[i]+1];
        
        if (!f[a[i]]) {
            f[a[i]] = true;
            if (!l && !r) ans++;
            else if (l && r) ans--;
        }
        else {
            f[a[i]] = false;
            if (!l && !r) ans--;
            else if (l && r) ans++;
        }
        
        cout << ans << nl;
    }

    return 0;
}