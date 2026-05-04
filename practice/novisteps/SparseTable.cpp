#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
const ll INF = 2e18;
const int IINF = 1e9 + 7;
// const int MOD = 998244353;
// const int MOD = 1000000007;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define rrep(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) ((ll)(x).size())
#define nl "\n"
#define pcnt(n) __builtin_popcountll(ll(n))
#define yes(ans) cout << ((ans) ? "Yes" : "No") << nl;
#define YES(ans) cout << ((ans) ? "YES" : "NO") << nl;
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }

#define DEBUG
#ifdef DEBUG
    template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
    #define debug(x) cerr << #x << ": " << (x) << endl
    #define debug_all(v) { cerr << #v << ": { "; for(auto& e : v) cerr << e << " "; cerr << "}" << endl; }
    #define debug_2d(v) { cerr << #v << ":" << endl; for(auto& r : v) { cerr << "  "; for(auto& e : r) cerr << e << " "; cerr << endl; } }
#else
    #define debug(x)
    #define debug_all(v)
    #define debug_2d(v)
#endif

struct SparseTable {
    ll n;
    ll LOG = 60;
    vector<vector<ll>> dp(LOG);

    SparseTable (vector<ll>& a) {
        ll n = a.size();
        ll log = 0;
        while ((1LL << log) <= n) LOG++;
        dp.assign(n);
    }
}

void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
}

// using Graph = vector<vector<ll>>;
// struct Edge { ll to; ll cost; };
// using Graph = vector<vector<Edge>>;

int main() {
    setup_fast_io();

    // ll n; cin >> n;
    // vector<ll> a(n);
    // rep(i, n) {
    //     cin >> a[i];
    // }
    ll n = 8;
    vector<ll> a = {1, 5, 4, 2, 3, 6, 5, 8};
    vector<ll> power(61, 1);
    rep(i, 60) {
        power[i+1] = power[i] * 2;
    }

    ll LOG = 0;
    while (power[LOG] < n) LOG++;
    debug(LOG);
    vector<vector<ll>> dp(LOG+1, vector<ll> (n, 0));
    for (int i = 0; i < n; i++) {
        dp[0][i] = a[i];
    }

    for (int k = 1; k <= LOG; k++) {
        for (int i = 0; i < n; i++) {
            debug(i+power[k-1]);
            if (i+power[k-1] < n) dp[k][i] = min(dp[k-1][i], dp[k-1][i+power[k-1]]);
            debug(dp[k][i]);
        }
    }
    debug_2d(dp);

    vector<ll> l = {0, 3, 5, 2};
    vector<ll> r = {7, 7, 7, 7};

    auto query = [&](ll x) -> ll {
        ll log = 0;
        ll res = INF;
        ll idx = 0;
        while (power[log] < x) log++;
        for (int i = log-1; i >= 0; i--) {
            if ((x >> i) & 1) {
                chmin(res, dp[i][idx]);
                idx += power[i];
            }
        }
        return res;
    };

    debug_2d(dp);

    for (int i = 0; i < 4) 

    

    return 0;
}