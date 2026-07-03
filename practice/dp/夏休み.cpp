#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
using vll = vector<ll>;
using vvll = vector<vll>;
using Graph = vvll;
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (T& x : v) is >> x; return is; }
template <typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
const ll INF = 2e18;
// const ll MOD = 998244353;
// const ll MOD = 1000000007;
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

// #define DEBUG
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

void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
}

// Doubling db(next_states);
struct Doubling {
    const ll LOG = 60;
    ll n;
    vector<vector<ll>> dp;

    Doubling(const vector<ll>& next_states) {
        n = next_states.size();
        dp.assign(LOG, vector<ll> (n, -1));

        for (ll i = 0; i < n; i++) {
            dp[0][i] = next_states[i];
        }

        for (ll k = 0; k < LOG - 1; k++) {
            for (ll v = 0; v < n; v++) {
                if (dp[k][v] == -1) {
                    dp[k + 1][v] = -1;
                }
                else {
                    dp[k + 1][v] = dp[k][dp[k][v]];
                }
            }
        }
    }

    ll query(ll l, ll r) {
        ll cur = l;
        ll ans = 0;
        for (int k = LOG-1; k >= 0; k--) {
            if (dp[k][cur] <= r + 1) {
                ans += (1LL << k);
                cur = dp[k][cur];
            }
        }
        return ans;
    }
};

int main() {
    setup_fast_io();

    ll n, m, q; cin >> n >> m >> q;
    vll a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
    }

    ll MAX = n + 2;
    vector<ll> suff_min(n+3, MAX);
    rep(i, m) {
        chmin(suff_min[a[i]], b[i] + 1);
    }

    ll M = MAX;
    for (int i = n+2; i >= 0; i--) {
        chmin(M, suff_min[i]);
        suff_min[i] = M;
    }

    debug_all(suff_min);

    Doubling db(suff_min);

    while (q--) {
        ll l, r; cin >> l >> r;
        cout << db.query(l, r) << nl;
    }


    return 0;
}