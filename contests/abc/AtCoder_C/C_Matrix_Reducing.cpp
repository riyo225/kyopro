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

    ll h1, w1, h2, w2;
    cin >> h1 >> w1;
    vector<vector<ll>> a(h1, vector<ll> (w1));
    rep(i, h1) {
        rep(j, w1) {
            cin >> a[i][j];
        }
    }
    cin >> h2 >> w2; 
    vector<vector<ll>> b(h2, vector<ll> (w2));
    rep(i, h2) {
        rep(j, w2) {
            cin >> b[i][j];
        }
    }

    bool ans = false;
    for (long long bith = 0; bith < (1LL << h1); bith++) {
        for (long long bitw = 0; bitw < (1LL << w1); bitw++) {
            ll H = popcount(bith);
            ll W = popcount(bitw);
            if (H != h2 || W != w2) continue;
            vector<vector<ll>> c(H, vector<ll> (W));
            ll x = 0, y = 0; 
            for (long long i = 0; i < h1; i++) {
                if ((bith >> i) & 0) continue;
                for (long long j = 0; j < w1; j++) {
                    if ((bitw >> j) & 1LL) {
                        c[x][y] = a[i][j];
                    }
                    y++;
                }
                x++;
            }

            bool flag = true;
            rep(i, h2) {
                rep(j, w2) {
                    if (b[i][j] != c[i][j]) {
                        flag = false;
                    }
                }
            }
            if (flag) {
                ans = true;
            }
        }
    }
    yes_no(ans);

    return 0;
}