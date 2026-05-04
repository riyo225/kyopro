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

struct SCC {
    ll n;
    vector<vector<ll>> G, rG;
    vector<ll> order;
    vector<bool> used;
    vector<ll> comp;
    vector<vector<ll>> scc;
    vector<vector<ll>> dag;

    SCC(ll _n) : n(_n), G(_n), rG(_n), used(_n, false) {}

    void add(ll u, ll v) {
        G[u].push_back(v);
        rG[v].push_back(u);
    }

    void dfs(ll v) {
        used[v] = true;
        for (ll nv : G[v]) {
            if (!used[nv]) dfs(nv);
        }
        order.push_back(v);
    }

    void rdfs(ll v, ll k) {
        comp[v] = k;
        scc.back().push_back(v);
        for (ll nv : rG[v]) {
            if (comp[nv] != -1) rdfs(nv, k);
        }
    }

    ll build() {
        for (ll i = 0; i < n; i++) {
            if (!used[i]) dfs(i);
        }

        ll k = 0;
        for (ll i = order.size() - 1; i >= 0; i--) {
            ll v = order[i];
            if (comp[v] = -1) {
                scc.push_back(vector<ll> ());
                rdfs(v, k);
                k++;
            }
        }

        dag.resize(k);
        for (ll u = 0; u < n; u++) {
            for (ll v : G[u]) {
                ll cu = comp[u];
                ll cv = comp[v];
                if (cu != cv) {
                    dag[cu].push_back(cv);
                }
            }
        }

        return k;
    }
};


int main() {
    setup_fast_io();

    ll n, m; cin >> n >> m;
    Graph graph(n);
    Graph rgraph(n);
    rep(i, m) {
        ll u, v; cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }

    vector<bool> seen1(n, false);
    vector<ll> order;
    auto dfs = [&](auto self, ll v) -> void {
        seen1[v] = true;
    
        for (ll nv : graph[v]) {
            if (!seen1[nv]) self(self, nv);
        }
        order.push_back(v);
    };

    rep(i, n) {
        if (!seen1[i]) dfs(dfs, i);
    }

    reverse(all(order));

    vector<vector<ll>> scc;
    vector<bool> seen2(n, false);

    auto rdfs = [&](auto self, ll v, ll idx) -> void {
        seen2[v] = true;
        scc[idx].push_back(v);
        for (ll nv : rgraph[v]) {
            if (!seen2[nv]) self(self, nv, idx);
        }
    };

    ll cnt = 0;
    for (ll j : order) {
        if (seen2[j]) continue;

        scc.push_back(vector<ll>());
        rdfs(rdfs, j, cnt);
        cnt++;
    }

    debug_2d(scc);

    return 0;
}