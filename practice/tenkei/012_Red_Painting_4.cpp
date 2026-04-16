#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
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
#define popcount(n) __builtin_popcountll(n);
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

    ll h, w;
    cin >> h >> w;
    UnionFind uf(h*w);
    vector<vector<bool>> vec(h, vector<bool> (w, false));
    ll q;
    cin >> q;
    const int dr[] = {1, 0, -1, 0}; const int dc[] = {0, 1, 0, -1};
    auto is_inside = [&](int r, int c) { return 0 <= r && r < h && 0 <= c && c < w; };
    auto is_outside = [&](int r, int c) { return r < 0 || h <= r || c < 0 || w <= c; };
    auto get_id = [&](int r, int c) { return r * w + c; };
    auto get_2d = [&](int id)  { return make_pair(id / w, id % w); };
    while (q > 0) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll r, c;
            cin >> r >> c;
            r--; c--;
            auto id = get_id(r, c);
            vec[r][c] = true;
            rep(i, 4) {
                ll nr = r + dr[i];
                ll nc = c + dc[i];

                if (is_outside(nr, nc)) continue;
                if (vec[nr][nc]) {
                    auto nid = get_id(nr, nc);
                    uf.unite(id, nid);
                }
            }
        }
        else {
            ll r1, r2, c1, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--; c1--; r2--; c2--;
            if (r1 == r2 && c1 == c2) {
                yes_no(vec[r1][c1]);
            }
            else yes_no(uf.same(get_id(r1, c1), get_id(r2, c2)));
        }
        q--;
    }

    return 0;
}