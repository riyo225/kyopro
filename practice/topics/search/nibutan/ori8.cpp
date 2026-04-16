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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> w1, w2;
    repbit(b, n/2) {
        ll s = 0;
        rep(i, n/2) {
            if (b & (1LL<<i)) {
                s += a[i];
            }
        }
        if (s != 0) {
            w1.push_back(s);
        }
    }
    for (ll b = 0; b < (1LL<<(n-n/2)); b++) {
        ll s = 0;
        rep(i, n-n/2) {
            if (b & (1LL<<i)) {
                s += a[i+n/2];
            }
        }
        if (s != 0) {
            w2.push_back(s);
        }
    }
    sort(all(w1)), sort(all(w2));
    bool flag = false;
    rep(i, sz(w1)) {
        ll k = x - w1[i];
        auto judge = [&](ll x) { return w2[x] >= k; };
        ll ng = -1, ok = sz(w2);
        while (ok - ng > 1) {
            ll mid = (ng + ok) / 2;
            if (judge(mid)) ok = mid;
            else ng = mid;
        }
        if (w1[i] + w2[ok] == x) flag = true;
    }
    yes_no(flag);
    
    return 0;
}