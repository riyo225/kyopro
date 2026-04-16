#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
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
#define popcount(n) __builtin_popcountll(n);
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

    ll l, r, d, u;
    cin >> l >> r >> d >> u;

    ll ans = 0;
    for (ll i = l; i <= r; i++) {
        ll I = abs(i);
        ll J = -1 * I;
        debug(i);
        if (I % 2 == 0) {
            if (d > I || u < J) {
                ll U = u % 2 == 0 ? u : u-1;
                ll D = d % 2 == 0 ? d : d+1;
                ans += (U - D) / 2 + 1;
            }
            else if (J <= d && u <= I) {
                ans += abs(u - d + 1);
            }
            else if (J <= d && u > I) {
                ll U = u % 2 == 0 ? u : u-1;
                ans += (I - d + 1) + (U - I) / 2;
            }
            else if (J > d && u <= I) {
                ll D = d % 2 == 0 ? d : d+1;
                ans += (u - J + 1) + (J - D) / 2;
            }
            else {
                ll U = u % 2 == 0 ? u : u-1;
                ll D = d % 2 == 0 ? d : d+1;
                ans += (I - J + 1) + (U - I) / 2 + (J - D) / 2;
            }
        }
        else {
            if (max(I+1, d) <= u) {
                ll U = u % 2 == 0 ? u : u-1;
                ans += (U - max(I+1, d)) / 2 + 1;
            }
            if (min(J-1, u) >= d) {
                ll D = d % 2 == 0 ? d : d+1;
                ans += (min(J-1, u) - D) / 2 + 1;
            }
        }
        debug(ans);
    }

    cout << ans << nl;

    return 0;
}