#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 2e9;
const ll INF_LL = 9e18;
const int MOD = 1000000007; // 998244353
const double PI = acos(-1);
// const string ALPHA_LOWER = "abcdefghijklmnopqrstuvwxyz"; // 必要ならコメント解除
// const string ALPHA_UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 必要ならコメント解除
const int DX8[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int DY8[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int DX4[] = {1, 0, -1, 0};
const int DY4[] = {0, 1, 0, -1};
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

// デバッグ出力を有効にするには、以下の行のコメントアウトを解除してください。
#define DEBUG
#ifdef DEBUG
    #define debug(x) cerr << #x << ": " << (x) << endl
    #define debug_vec(vec) { cerr << #vec << ": "; for(const auto& elem : vec) cerr << elem << " "; cerr << endl; }
    #define debug_pair(p) cerr << #p << ": (" << (p).first << ", " << (p).second << ")" << endl
    #define debug_2d_vec(vec2d) { cerr << #vec2d << ":" << endl; for(const auto& row : vec2d) { cerr << "  "; for(const auto& elem : row) cerr << elem << " "; cerr << endl; } }
    // mapのデバッグ出力は必要性が低いが、もし使うなら以下を使用
    // #define debug_map(m) { cerr << #m << ": "; for(const auto& [key, val] : m) cerr << "(" << key << ":" << val << ") "; cerr << endl; }
#else
    #define debug(x)
    #define debug_vec(vec)
    #define debug_pair(p)
    #define debug_2d_vec(vec2d)
    // #define debug_map(m)
#endif

void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);
}

struct Edge {
    ll to;
    ll cost;
};
// using Graph = vector<vector<ll>>;
// using Graph = vector<vector<Edge>>;

ll power(ll a, ll t, ll m) {
    ll res = 1;
    a %= m;
    while (t != 0) {
        if  (t & 1) res = (__int128)res * a % m;
        a = (__int128)a * a % m;
        t >>= 1;
    }
    return res;
};

struct Tree {
    int n;
    int log_n;
    vector<vector<int>> graph;
    vector<vector<int>> par;
    vector<int> depth;
    vector<long long> dist;

    Tree(int n) : n(n), graph(n), depth(n), dist(n) {
        log_n = 32 - __builtin_clz(n);
    }

    // void add_edge(int u, int v, long long w = 1) {
    //     g[u].push_back(v);
    //     g[v].push_back(u);
    // }

    // void build

    // void dfs(int v, int p, int d, long long cost) {
        
    // }
};

struct Doubling {
    const ll LOG = 60;
    ll n;
    vector<vector<ll>> dp;

    Doubling(const vector<ll>& next_states) {
        n = next_states.size();
        dp.assign(LOG, vector<ll> (n, -1));

        for (ll i = 0; i < n; i++) {
            dp[0][i] = next_states[i];
        }

        for (ll k = 0; k < LOG - 1; k++) {
            for (ll v = 0; v < n; v++) {
                if (dp[k][v] == -1) {
                    dp[k + 1][v] = -1;
                }
                else {
                    dp[k + 1][v] = dp[k][dp[k][v]];
                }
            }
        }
    }

    ll query(ll v, ll k) {
        for (ll i = 0; i < LOG; i++) {
            if ((k >> i) & 1) {
                v = dp[i][v];
                if (v == -1) break;
            }
        }
        return v;
    }
};


int main() {
    setup_fast_io();

    multiset<ll> mst = {1, 2, 2, 3, 3, 3};
    cout << mst.size() << nl;

    return 0;
}