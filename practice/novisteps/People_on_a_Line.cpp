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

struct UnionFind {
    ll n, group_count;
    vector<ll> par;

    UnionFind(ll n) : n(n), par(n, -1), group_count(n) {}

    ll root(ll x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    bool unite(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        group_count--;
        return true;
    }

    bool same(ll x, ll y) { return root(x) == root(y); }

    ll size(ll x) { return -par[root(x)]; }

    vector<vector<ll>> groups() {
        vector<vector<ll>> res(n);
        for (ll i = 0; i < n; i++) res[root(i)].push_back(i);
        res.erase(
            remove_if(res.begin(), res.end(), [](const vector<ll>& v) { return v.empty(); }),
            res.end()
        );
        return res;
    }
};

template <typename T>
struct WeightedUnionFind {
    ll n, group_count;
    vector<ll> par;
    vector<T> diff_weight;

    WeightedUnionFind(ll n) : n(n), par(n, -1), group_count(n), diff_weight(n, 0) {}

    ll root(ll x) {
        if (par[x] < 0) return x;
        ll r = root(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = r;
    }

    T weight(ll x) {
        root(x);
        return diff_weight[x];
    }

    T diff(ll x, ll y) {
        return weight(y) - weight(x);
    }

    bool unite(ll x, ll y, T w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) {
            swap(x, y);
            w = -w;
        }
        par[x] += par[y];
        par[y] = x;
        diff_weight[y] = w;
        group_count--;
        return true;
    }

    bool same(ll x, ll y) { return root(x) == root(y); }

    ll size(ll x) { return -par[root(x)]; }

    vector<vector<ll>> groups() {
        vector<vector<ll>> res(n);
        for (ll i = 0; i < n; i++) res[root(i)].push_back(i);
        res.erase(
            remove_if(res.begin(), res.end(), [](const vector<ll>& v) { return v.empty(); }),
            res.end()
        );
        return res;
    }
};

int main() {
    setup_fast_io();

    ll n, m; cin >> n >> m;
    WeightedUnionFind<ll> wuf(n);
    bool ans = true;
    rep(i, m) {
        ll l, r, d; cin >> l >> r >> d; l--; r--;
        if (!wuf.same(l, r)) {
            wuf.unite(l, r, d);
        }
        else {
            if (wuf.diff(l, r) == d) {
                wuf.unite(l, r, d);
            }
            else ans = false;
        }
    }

    yes(ans);

    return 0;
}