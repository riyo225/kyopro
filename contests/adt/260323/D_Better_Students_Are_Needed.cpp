#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;
// const int MOD = 998244353;
// const int MOD = 1000000007;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define rrep(i, n) for (ll i = (ll)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) ((ll)(x).size())
#define nl "\n"
#define popcount(n) __builtin_popcountll(n)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << nl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << nl;
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }

// #define DEBUG
#ifdef DEBUG
    #define debug(x) cerr << #x << ": " << (x) << endl
    #define debug_vec(vec) { cerr << #vec << ": "; for(const auto& elem : vec) cerr << elem << " "; cerr << endl; }
    #define debug_pair(p) cerr << #p << ": (" << (p).first << ", " << (p).second << ")" << endl
    #define debug_2d_vec(vec2d) { cerr << #vec2d << ":" << endl; for(const auto& row : vec2d) { cerr << "  "; for(const auto& elem : row) cerr << elem << " "; cerr << endl; } }
    #define debug_map(m) { cerr << #m << ": "; for(const auto& [key, val] : m) cerr << "(" << key << ":" << val << ") "; cerr << endl; }
#else
    #define debug(x)
    #define debug_vec(vec)
    #define debug_pair(p)
    #define debug_2d_vec(vec2d)
    #define debug_map(m)
#endif

void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
}

// using Graph = vector<vector<ll>>;
// using Graph = vector<vector<Edge>>;

int main() {
    setup_fast_io();

    ll n, X, Y, Z;
    cin >> n >> X >> Y >> Z;
    vector<pll> a(n), b(n), s(n, {0, 0});
    vector<bool> ac(n, false);

    rep(i, n) {
        cin >> a[i].first;
        a[i].second = i;
        s[i].first += a[i].first;
        s[i].second = i;
    }

    rep(i, n) {
        cin >> b[i].first;
        b[i].second = i;
        s[i].first += b[i].first;
    }

    sort(all(a), [](pll x, pll y) {
        if (x.first == y.first) {
            return x.second < y.second;
        }
        return x.first > y.first;
    });

    sort(all(b), [](pll x, pll y) {
        if (x.first == y.first) {
            return x.second < y.second;
        }
        return x.first > y.first;
    });

    sort(all(s), [](pll x, pll y) {
        if (x.first == y.first) {
            return x.second < y.second;
        }
        return x.first > y.first;
    });

    rep(i, n) {
        if (X == 0) break;
        if (ac[a[i].second]) continue;
        else {
            ac[a[i].second] = true;
            X--;
        }
    }

    rep(i, n) {
        if (Y == 0) break;
        if (ac[b[i].second]) continue;
        else {
            ac[b[i].second] = true;
            Y--;
        }
    }

    rep(i, n) {
        if (Z == 0) break;
        if (ac[s[i].second]) continue;
        else {
            ac[s[i].second] = true;
            Z--;
        }
    }

    for (int i = 0; i < n; i++) {
        if (ac[i]) cout << i + 1 << nl;
    }
    return 0;
}