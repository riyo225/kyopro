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
    #define debug_vec_pair(vec) { cerr << #vec << ": "; for (const auto& [f, s] : vec) cerr << "(" << f << ", " << s << ") "; cerr << endl; }
#else
    #define debug(x)
    #define debug_vec(vec)
    #define debug_pair(p)
    #define debug_2d_vec(vec2d)
    #define debug_map(m)
    #define debug_vec_pair(vec)
#endif

void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
}

struct Edge {
    ll to; ll cost;
};
using Graph = vector<vector<Edge>>;

struct LCA {
    ll N, K;
    vector<vector<ll>> parent;
    vector<ll> depth;
    vector<ll> dist_root;

    LCA(const vector<vector<Edge>>& G, ll root = 0) {
        N = G.size();
        K = 1;
        while ((1 << K) < N) K++;

        parent.assign(K, vector<ll>(N, -1));
        depth.assign(N, -1);
        dist_root.assign(N, 0);

        dfs(G, root, -1, 0, 0);

        for (ll k = 0; k + 1 < K; k++) {
            for (ll v = 0; v < N; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    void dfs(const vector<vector<Edge>>& G, ll v, ll p, ll d, ll cur_dist) {
        parent[0][v] = p;
        depth[v] = d;
        dist_root[v] = cur_dist;
        for (auto e : G[v]) {
            if (e.to != p) {
                dfs(G, e.to, v, d + 1, cur_dist + e.cost);
            }
        }
    }

    ll get(ll u, ll v) {
        if (depth[u] < depth[v]) swap(u, v);

        ll diff = depth[u] - depth[v];
        for (ll k = 0; k < K; k++) {
            if ((diff >> k) & 1) {
                u = parent[k][u];
            }
        }

        if (u == v) return u;

        for (ll k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }

        return parent[0][u];
    }

    ll dist(ll u, ll v) {
        return dist_root[u] + dist_root[v] - 2 * dist_root[get(u, v)];
    }
};


struct UnionFind {
    vector<long long> par;
    long long group_count;

    UnionFind(long long N) : par(N, -1), group_count(N) {}

    long long root(long long x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    bool unite(long long x, long long y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        group_count--;
        return true;
    }

    bool same(long long x, long long y) {
        return root(x) == root(y);
    }

    ll size(ll x) {
        return -par[root(x)];
    }
};

int main() {
    setup_fast_io();

    ll n;
    cin >> n;
    Graph graph(n);
    vector<pair<ll, pll>> vec;
    vector<vector<ll>> a(n, vector<ll> (n, -1));
    rep(i, n-1) {
        for (int j = i+1; j < n; j++) {
            cin >> a[i][j];
            vec.push_back({a[i][j], {i, j}});
        }
    }

    UnionFind uf(n);

    sort(all(vec));
    
    ll cnt = n-1;
    for (int i = 0; i < sz(vec); i++) {
        auto [v, w] = vec[i];
        auto [x, y] = w;
        if (uf.same(x, y)) continue;
        else {
            graph[x].push_back({y, v});
            graph[y].push_back({x, v});
            uf.unite(x, y);
            cnt--;
        }
        if (cnt == 0) break;
    }


    LCA lca(graph, 0);

    bool ans = true;
    for (ll i = 0; i < n-1; i++) {
        for (ll j = i+1; j < n; j++) {
            if (lca.dist(i, j) != a[i][j]) ans = false;
        }
        cout << nl;
    }

    yes_no(ans);

    return 0;
}