#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;
const int MOD = 998244353;
// const int MOD = 1000000007;
const double PI = acos(-1);
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define rrep(i, n) for (ll i = (ll)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) ((ll)(x).size())
#define nl "\n"
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
#else
    #define debug(x)
    #define debug_vec(vec)
    #define debug_pair(p)
    #define debug_2d_vec(vec2d)
    #define debug_map(m)
#endif

void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
}

// using Graph = vector<vector<ll>>;
// using Graph = vector<vector<Edge>>;

template<typename T>
struct MaxFlow {
    struct Edge {
        ll to;
        T cap;
        ll rev;
    };

    vector<vector<Edge>> graph;
    vector<ll> level;
    vector<ll> iter;

    MaxFlow(ll n) : graph(n), level(n), iter(n) {}

    void add_edge(ll from, ll to, T cap) {
        graph[from].push_back({to, cap, graph[to].size()});
        graph[to].push_back({from, 0, graph[from].size() - 1});
    }

    void bfs(ll s) {
        fill(level.begin(), level.end(), -1);
        queue<ll> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            ll v = q.front();
            q.pop();
            for (auto& e : graph[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    T dfs(ll v, ll t, T f) {
        if (v == t) return f;
        for (ll& i = iter[v]; i < graph[v].size(); i++) {
            Edge& e = graph[v][i];
            if ((e.cap > 0) && level[v] < level[e.to]) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T flow(ll s, ll t) {
        T flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
            T f;
            while ((f = dfs(s, t, numeric_limits<T>::max())) > 0) {
                flow += f;
            }
        }
    }
};

int main() {
    setup_fast_io();

    ll n, m;
    cin >> n >> m;
    MaxFlow<ll> mf(n);
    rep(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        mf.add_edge(a, b, c);
    }

    cout << mf.flow(0, n-1) << nl;

    return 0;
}
