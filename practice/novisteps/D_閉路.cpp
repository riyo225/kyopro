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

// using Graph = vector<vector<ll>>;
// using Graph = vector<vector<Edge>>;


struct Edge { long long to; long long cost; };
using Graph = vector<vector<Edge>>;

// 重み付木の LCA 重みがないときは重み 1 として計算する
struct LCA {
    long long N, K;
    vector<vector<long long>> par;
    vector<long long> depth;
    vector<long long> dist_root;

    LCA(const vector<vector<Edge>>& G, long long root = 0) {
        N = G.size();
        K = 1;
        while ((1 << K) < N) K++;

        par.assign(K, vector<long long> (N, -1));
        depth.assign(N, -1);
        dist_root.assign(N, 0);

        dfs(G, root, -1, 0, 0);

        for (long long k = 0; k < K - 1; k++) {
            for (long long v = 0; v < N; v++) {
                if (par[k][v] < 0) {
                    par[k + 1][v] = -1;
                }
                else {
                    par[k + 1][v] = par[k][par[k][v]];
                }
            }
        }
    }

    void dfs(const vector<vector<Edge>>& G, long long v, long long p, long long d, long long cur_dist) {
        par[0][v] = p;
        depth[v] = d;
        dist_root[v] = cur_dist;
        for (auto e : G[v]) {
            if (e.to != p) {
                dfs(G, e.to, v, d + 1, cur_dist + e.cost);
            }
        }
    }

    long long get_ancestor(long long u, long long k) {
        for (long long i = 0; i < K; i++) {
            if ((k >> i) & 1) {
                u = par[i][u];
                if (u == -1) return -1;
            }
        }
        return u;
    }

    long long get(long long u, long long v) {
        if (depth[u] < depth[v]) swap(u, v);

        long long diff = depth[u] - depth[v];
        u = get_ancestor(u, diff);

        if (u == v) return u;

        for (long long k = K - 1; k >= 0; k--) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }

        return par[0][u];
    }

    long long dist(long long u, long long v) {
        return dist_root[u] + dist_root[v] - 2 * dist_root[get(u, v)];
    }
};

int main() {
    setup_fast_io();

    ll n;
    cin >> n;
    Graph graph(n);
    rep(i, n-1) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        graph[x].push_back({y, 1});
        graph[y].push_back({x, 1});
    }

    LCA lca(graph);

    ll q;
    cin >> q;
    while (q > 0) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        cout << lca.dist(u, v) + 1 << nl;
        q--;
    }
    

    return 0;
}