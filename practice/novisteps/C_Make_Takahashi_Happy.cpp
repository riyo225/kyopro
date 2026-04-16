#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;
const int MOD = 998244353;
// const int MOD = 1000000007;
const int dx[] = {1, 0};
const int dy[] = {0, 1};
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
    vector<vector<ll>> a(h, vector<ll> (w));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }

    ll ans = 0;
    map<ll, ll> mp;
    auto dfs = [&](auto self, ll x, ll y) -> void {
        if (x == h-1 && y == w-1) {
            ans++;
            debug_map(mp);
            return;
        }

        rep(i, 2) {
            ll nx = x + dx[i];
            ll ny = y + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

            if (mp[a[nx][ny]] != 0) continue;
            mp[a[nx][ny]]++;
            self(self, nx, ny);
            mp[a[nx][ny]]--;
        }
    };

    mp[a[0][0]]++;
    dfs(dfs, 0, 0);
    cout << ans << nl;

    return 0;
}