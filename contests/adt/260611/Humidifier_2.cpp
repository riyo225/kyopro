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


int main() {
    setup_fast_io();

    ll h, w, d; cin >> h >> w >> d;
    vector<vector<char>> vec(h, vector<char> (w));
    rep(i, h) {
        rep(j, w) {
            cin >> vec[i][j];
        }
    }

    ll ans = 0;
    rep(x1, h) rep(y1, w) {
        rep(x2, h) rep(y2, w) {
            if (x1 == x2 && y1 == y2) continue;
            if (vec[x1][y1] == '#' || vec[x2][y2] == '#') continue;

            const ll dr[] = {1, 0, -1, 0}; const ll dc[] = {0, 1, 0, -1};
            string DIRS = "DRUL";
            const ll dr8[] = {1, 1, 0, -1, -1, -1, 0, 1}; const ll dc8[] = {0, 1, 1, 1, 0, -1, -1, -1};
            auto is_inside = [&](ll r, ll c) { return 0 <= r && r < h && 0 <= c && c < w; };
            auto is_outside = [&](ll r, ll c) { return r < 0 || h <= r || c < 0 || w <= c; };
            auto get_id = [&](ll r, ll c) { return r * w + c; };
            auto get_2d = [&](ll id)  { return make_pair(id / w, id % w); };
            
            vector<vector<ll>> dist(h, vector<ll> (w, -1));
            vector<vector<ll>> from(h, vector<ll> (w, -1));
            queue<pll> que;
            dist[x1][y1] = 0;
            dist[x2][y2] = 0;
            que.push({x1, y1});
            que.push({x2, y2});
            
            while (!que.empty()) {
                auto [r, c] = que.front();
                que.pop();
                if (dist[r][c] == d) continue;
            
                for (int i = 0; i < 4; i++) {
                    ll nr = r + dr[i];
                    ll nc = c + dc[i];
                    if (is_outside(nr, nc)) continue;
                    if (dist[nr][nc] != -1) continue;
                    dist[nr][nc] = dist[r][c] + 1;
                    from[nr][nc] = i;
                    que.push({nr, nc});
                }
            }

            ll cnt = 0;
            rep(i, h) rep(j, w) {
                if (dist[i][j] != -1 && vec[i][j] == '.') cnt++;
            }
            chmax(ans, cnt);
        }
    }

    cout << ans << nl;

    return 0;
}