#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;
// const int MOD = 998244353;
// const int MOD = 1000000007;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define rrep(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
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
// struct Edge { ll to; ll cost; };
// using Graph = vector<vector<Edge>>;

int main() {
    setup_fast_io();

    ll h, w;
    cin >> h >> w;
    vector<vector<char>> vec(h, vector<char> (w));
    ll sr, sc, gr, gc;
    rep(i, h) {
        rep(j, w) {
            cin >> vec[i][j];
            if (vec[i][j] == 'S') {
                sr = i; sc = j;
            }
            if (vec[i][j] == 'G') {
                gr = i; gc = j;
            }
        }
    }

    // queue<pll> que;
    // vector<vector<ll>> dist(h, vector<ll> (w, -1));
    // dist[sr][sc] = 0;
    // que.push({sr, sc});

    const int dr[] = {1, 0, -1, 0}; const int dc[] = {0, 1, 0, -1};
    auto is_inside = [&](int r, int c) { return 0 <= r && r < h && 0 <= c && c < w; };
    auto is_outside = [&](int r, int c) { return r < 0 || h <= r || c < 0 || w <= c; };
    auto get_id = [&](int r, int c) { return r * w + c; };
    auto get_2d = [&](int id)  { return make_pair(id / w, id % w); };

    // while (!que.empty() && dist[gr][gc] == -1) {
    //     ll r = que.front().first;
    //     ll c = que.front().second;
    //     que.pop();

    //     for (int i = 0; i < 4; i++) {
    //         ll nr = r + dr[i];
    //         ll nc = r + dc[i];
    //     }
        
        
    // }

    auto push = [&](ll i) -> char {
        if (i == 0) return 'D';
        if (i == 1) return 'R';
        if (i == 2) return 'U';
        if (i == 3) return 'L';
        return 'X';
    };

    bool flag = false;
    // vector<vector<bool>> seen(h, vector<bool> (w, false));
    vector<vector<vector<bool>>> seen(h, vector<vector<bool>> (w, vector<bool> (5, false)));
    seen[sr][sc][4] = true;
    string s = "";
    auto dfs = [&](auto self, ll r, ll c, ll dir) -> void {
        if (flag) return;
        if (r == gr && c == gc) {
            flag = true;
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (vec[r][c] == 'o' && dir != i) continue;
            if (vec[r][c] == 'x' && dir == i) continue;

            ll nr = r + dr[i];
            ll nc = c + dc[i];
            if (vec[r][c] == 'o' && is_outside(nr, nc)) return;
            if (is_outside(nr, nc) || vec[nr][nc] == '#') continue;
            if (seen[nr][nc][i]) continue;

            seen[nr][nc][i] = true;
            s.push_back(push(i));
            self(self, nr, nc, i);
            if (!flag) s.pop_back();
            else return;
        }
    };
    dfs(dfs, sr, sc, -1);
    yes_no(!s.empty());
    cout << s << nl;

    return 0;
}