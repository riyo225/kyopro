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

// [prefix: DST]

template <typename T>
struct DST {
    vector<vector<T>> table;
    ll LOG = 0;

    DST(vector<T>& a) {
        ll n = a.size();
        while ((1LL << LOG) < n) LOG++;
        ll N = (1LL << LOG);
        a.resize(N);

        table.assign(LOG, vector<ll> (N, 0));
        for (ll i = 0; i < n; i++) {
            table[0][i] = a[i];
        }

        for (ll k = LOG-1; k >= 0; k--) {
        for (ll s = (1 << k); s < n; s += (1 << (k+1))) {
                table[k][s] = a[s];
                if (s-1 >= 0) table[k][s-1] = a[s-1];
                for (ll i = 1; i < (1 << k); i++) {
                    if (s + i < n) table[k][s+i] = table[k][s+i-1] + a[s+i];
                    if (s - i - 1 >= 0) table[k][s-i-1] = table[k][s-i] + a[s-i-1];
                }
            }
        }
    }

    T query(ll l, ll r) {
        if (r <= l) return 0;
        if (r - l == 1) return table[0][l];
        ll x = l ^ (r - 1);
        ll k = __lg(x);
        return table[k][l] + table[k][r-1];
    }
};

int main() {
    setup_fast_io();

    ll n = 8;
    vll a = {1, 2, 3, 4, 5, 6, 7, 8};

    ll LOG = 0;
    while ((1LL << LOG) < n) LOG++;

    vvll table(LOG, vll(n, 0));

    for (ll k = LOG-1; k >= 0; k--) {
        for (ll s = (1 << k); s < n; s += (1 << (k+1))) {
            table[k][s] = a[s];
            if (s-1 >= 0) table[k][s-1] = a[s-1];
            for (ll i = 1; i < (1 << k); i++) {
                if (s + i < n) table[k][s+i] = table[k][s+i-1] + a[s+i];
                if (s - i - 1 >= 0) table[k][s-i-1] = table[k][s-i] + a[s-i-1];
            }
        }
    }

    auto query = [&](ll l, ll r) -> ll {
        if (r <= l) return -1;
        if (l + 1 == r) return a[l];
        ll x = l ^ (r - 1);
        ll k = __lg(x);
        return table[k][l] + table[k][r-1];
    };

    cout << query(1, 4) << nl;

    debug_2d(table);

    return 0;
}