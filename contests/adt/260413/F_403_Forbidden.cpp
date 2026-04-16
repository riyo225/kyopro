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

// using Graph = vector<vector<ll>>;
// struct Edge { ll to; ll cost; };
// using Graph = vector<vector<Edge>>;

struct UnionFind {
    ll n;
    vector<ll> par;
    ll group_count;

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

int main() {
    setup_fast_io();

    ll n, m, q;
    cin >> n >> m >> q;
    vector<bool> al(n, false);
    vector<set<ll>> st(n);
    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll x, y; cin >> x >> y;
            x--; y--;
            st[x].insert(y);
        }
        else if (type == 2) {
            ll x; cin >> x; x--;
            al[x] = true;
        }
        else {
            ll x, y; cin >> x >> y; x--; y--;
            auto it = st[x].find(y);
            yes(al[x] || it != st[x].end());
        }
    }

    return 0;
}