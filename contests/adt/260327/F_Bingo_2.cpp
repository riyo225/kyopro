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

    ll n, t;
    cin >> n >> t;
    ll h = n;
    ll w = n;
    
    const int dr[] = {1, 0, -1, 0}; const int dc[] = {0, 1, 0, -1};
    auto is_inside = [&](int r, int c) { return 0 <= r && r < h && 0 <= c && c < w; };
    auto is_outside = [&](int r, int c) { return r < 0 || h <= r || c < 0 || w <= c; };
    auto get_id = [&](int r, int c) { return r * w + c; };
    auto get_2d = [&](int id)  { return make_pair(id / w, id % w); };

    vector<ll> r(h, 0), c(w, 0);
    ll x = 0;
    ll y = 0;
    vector<ll> a(t);
    rep(i, t) {
        cin >> a[i];
        a[i]--;
    }

    bool f = true;
    rep(i, t) {
        auto [R, C] = get_2d(a[i]);

        r[R]++;
        c[C]++;
        if (R == C) x++;
        if (R + C == n-1) {
            y++;
        }
        if (r[R] == n || c[C] == n || x == n || y == n) {
            f = false;
            cout << i + 1 << nl;
            break;
        }
    }
    if (f) cout << -1 << nl;



    return 0;
}