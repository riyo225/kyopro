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

struct EulerTour {
    vector<long long> in, out;
    vector<long long> tour;
    long long timer;

    EulerTour(const Graph& G, long long root = 0) {
        long long N = G.size();
        in.assign(N, -1);
        out.assign(N, -1);
        tour.assign(N, -1);
        timer = 0;

        auto dfs = [&](auto self, long long v, long long p) -> void {
            in[v] = timer;
            tour[timer] = v;
            timer++;

            for (const auto& e : G[v]) {
                if (e.to != p) {
                    self(self, e.to, v);
                }
            }

            out[v] = timer;
        };

        if (N > 0) dfs(dfs, root, -1);
    }

    pair<long long, long long> get_subtree_range(long long v) {
        return {in[v], out[v]};
    }
};

int main() {
    setup_fast_io();

    ll n;
    cin >> n;
    Graph graph(n);
    rep(i, n-1) {
        ll p;
        cin >> p;
        p--;
        graph[i+1].push_back({p, 1});
        graph[p].push_back({i+1, 1});
    }

    EulerTour et(graph, 0);
    vector<ll> depth(n, 0);

    auto dfs = [&](auto self, ll v, ll p, ll d) -> void {
        depth[v] = d;
        for (const auto& e : graph[v]) {
            ll nv = e.to;
            if (nv != p) {
                self(self, nv, v, d + 1);
            }
        }
    };
    dfs(dfs, 0, -1, 0);

    vector<vector<ll>> intime(n);
    rep(i, n) {
        intime[depth[i]].push_back(et.in[i]);
    }

    rep(i, n) {
        sort(all(intime[i]));
    }

    ll q;
    cin >> q;
    while (q--) {
        ll u, d;
        cin >> u >> d;
        u--;
        auto p = et.get_subtree_range(u);
        auto itl = lower_bound(all(intime[d]), p.first);
        auto itr = lower_bound(all(intime[d]), p.second);

        ll ans = itr - itl;

        cout << ans << nl;
    }

    return 0;
}