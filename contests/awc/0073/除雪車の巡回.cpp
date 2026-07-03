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

struct Edge { ll to; ll cost; };
using WGraph = vector<vector<Edge>>;

vector<ll> dijkstra(const WGraph& G, ll s) {
    vector<ll> dist(G.size(), INF);
    using P = pair<ll, ll>;
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d > dist[v]) continue;

        for (const auto& [nv, c] : G[v]) {
            if (dist[nv] > dist[v] + c) {
                dist[nv] = dist[v] + c;
                pq.push({dist[nv], nv});
            }
        }
    }
    return dist;
}

int main() {
    setup_fast_io();

    ll n, m; cin >> n >> m;
    WGraph graph(n);
    vll outdeg(n, 0);
    ll sum = 0;
    rep(i, m) {
        ll u, v, w; cin >> u >> v >> w; u--; v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        sum += w;
        outdeg[u]++;
        outdeg[v]++;
    }

    vector<ll> idx;
    rep(i, n) {
        if (outdeg[i] % 2 != 0) idx.push_back(i);
    }

    ll k = sz(idx);
    vector<ll> dp((1 << k), INF);
    dp[0] = 0;

    vector<vector<ll>> vec(k);
    rep(i, k) {
        vec[i] = dijkstra(graph, idx[i]);
    }

    for (int i = 0; i < (1 << k); i++) {
        for (int x = 0; x < k - 1; x++) {
            for (int y = x + 1; y < k; y++) {
                if (x == y) continue;
                if (i & (1 << x) || i & (1 << y)) continue;
                ll nbit = (i | (1 << x) | (1 << y));
                chmin(dp[nbit], dp[i] + vec[x][idx[y]]);
            }
        }
    }

    cout << sum + dp[(1 << k) - 1] << nl;

    return 0;
}