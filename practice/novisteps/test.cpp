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
struct Edge { long long to; long long cost; };
using Graph = vector<vector<Edge>>;

struct TreeDiameter {
    long long diameter;
    long long u, v;
    vector<long long> path;

    TreeDiameter(const Graph& G) {
        long long N = G.size();
        if (N == 0) return;

        auto get_far = [&](long long start) {
            vector<long long> dist(N, -1);
            vector<long long> par(N, -1);

            auto dfs = [&](auto self, long long cur, long long p, long long d) -> void {
                par[cur] = p;
                dist[cur] = d;
                for (auto& e : G[cur]) {
                    if (e.to != p) {
                        self(self, e.to, cur, d + e.cost);
                    }
                }
            };

            dfs(dfs, start, -1, 0);

            long long max_d = -1;
            long long far = start;
            for (long long i = 0; i < N; i++) {
                if (dist[i] > max_d) {
                    max_d = dist[i];
                    far = i;
                }
            }
            return make_tuple(max_d, far, par);
        };

        // 適当な頂点 0 から一番遠い頂点 u を探す
        auto [d0, u, p0] = get_far(0);
        auto [du, v, pu] = get_far(u);
        diameter = du;

        long long cur = v;
        while (cur != -1) {
            path.push_back(cur);
            cur = pu[cur];
        }
        reverse(path.begin(), path.end());
    }

    vector<long long> get_center() {
        vector<long long> centers;
        long long sz = path.size();
        if (sz % 2 != 0) {
            centers.push_back(path[sz / 2]);
        }
        else {
            centers.push_back(path[sz / 2 - 1]);
            centers.push_back(path[sz / 2]);
        }
    }
};

struct TrieNode {
    vector<long long> next;
    long long accept;
    long long count;

    TrieNode() {
        next.assign(2, -1);
        accept = 0;
        count = 0;
    }
};

struct BinaryTrie {
    vector<TrieNode> nodes;
    long long LOG;

    BinaryTrie(long long log = 60) : LOG(log) {
        nodes.push_back(TrieNode());
    }

    void insert(long long val) {
        long long cur = 0;
        for (long long i = LOG - 1; i >= 0; i--) {
            long long bit = (val >> i) & 1;
            
            if (nodes[cur].next[bit] == -1) {
                nodes[cur].next[bit] = nodes.size();
                nodes.push_back(TrieNode());
            }

            cur = nodes[cur].next[bit];
            nodes[cur].count++;
        }
        nodes[cur].accept++;
    }

    bool search(long long val) {
        long long cur = 0;
        for (char c : word) {
            long long idx = chartoll(c);
            if (nodes[cur].next[idx] == -1) {
                return false;
            }
            cur = nodes[cur].next[idx];
        }
        return nodes[cur].accept > 0;
    }

    long long count_val(long long val) {
        long long cur = 0;
        for (long long i = LOG - 1; i >= 0; i--) {
            long long bit = (val >> i) & 1;
            if (nodes[cur].next[bit] == -1) {
                return 0;
            }
            cur = nodes[cur].next[bit];
        }
        return nodes[cur].count;
    }

    long long count_prefix(const string& prefix) {
        long long cur = 0;
        for (char c : prefix) {
            long long idx = chartoll(c);
            if (nodes[cur].next[idx] == -1) {
                return 0;
            }
            cur = nodes[cur].next[idx];
        }
        return nodes[cur].count;
    }
};

int main() {
    setup_fast_io();

    

    return 0;
}