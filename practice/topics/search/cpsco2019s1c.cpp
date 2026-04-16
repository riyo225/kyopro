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
struct Edge
{
    ll to;
    ll cost;
};
using Graph = vector<vector<ll>>;
ll next_combination(ll sub) {
    ll x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<ll> ans;
    ll b = ((1LL)<<k)-1;
    for (;b < ((1LL)<<n); b = next_combination(b)) {
        ll sum = 0;
        rep(i, n) {
            if (b & ((1LL)<<i)) {
                sum += a[i];
            }
        }
        ans.push_back(sum);
    }

    ll Ans = INF;
    rep(i, sz(ans)) {
        ll sum = 0;
        while (ans[i] > 0) {
            ll c = ans[i] % 10;
            if (c >= 5) {
                sum += 1;
                c -= 5;
            }
            sum += c;
            ans[i] /= 10;
        }
        Ans = min(Ans, sum);
    }

    cout << Ans << nl;
    return 0;
}