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

int main() {
    setup_fast_io();

    ll h, w;
    cin >> h >> w;
    vector<vector<char>> g(h, vector<char> (w));
    rep(i, h) {
        rep(j, w) {
            cin >> g[i][j];
        }
    }
    vector<vector<bool>> visit(h, vector<bool> (w, false));

    auto check = [&](ll nr, ll nc) -> bool {
        return (nr >= 0 && nr < h && nc >= 0 && nc < w);
    };

    ll r = 0;
    ll c = 0;
    bool flag = true;
    while (flag) {
        pll p = {r, c};
        // debug_pair(p);

        visit[r][c] = true;
        char C = g[r][c];
        ll dr = 0, dc = 0;
        if (C == 'U') dr = -1;
        else if (C == 'D') dr = 1;
        else if (C == 'L') dc = -1;
        else dc = 1;
        ll nr = r + dr;
        ll nc = c + dc;
        
        if (check(nr, nc)) {
            if (visit[nr][nc]) {
                cout << -1 << nl;
                flag = false;
            }
            else {
                r = nr;
                c = nc;
            }
        }
        else {
            cout << r+1 << " " << c+1 << nl;
            flag = false;
        }
    }

    return 0;
}