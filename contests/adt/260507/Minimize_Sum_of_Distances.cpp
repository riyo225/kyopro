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

struct Edge { long long to; long long cost; };
using WGraph = vector<vector<Edge>>;

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

    ll n; cin >> n;
    WGraph wgraph(n);

    

    return 0;
}