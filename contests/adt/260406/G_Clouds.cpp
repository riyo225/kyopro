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

struct Imos2D {
    long long H, W;
    vector<vector<long long>> data;

    Imos2D(long long h, long long w) : H(h), W(w), data(h + 2, vector<long long> (w + 2, 0)) {}

    // [r1, r2) x [c1, c2) に v を加算
    void add (long long r1, long long r2, long long c1, long long c2, long long v) {
        r1 = max(0LL, r1); c1 = max(0LL, c1);
        r2 = min(H, r2); c2 = min(W, c2);
        if (r1 >= r2 || c1 >= c2) return;

        data[r1][c1] += v;
        data[r1][c2] -= v;
        data[r2][c1] -= v;
        data[r2][c2] += v;
    }

    vector<vector<long long>> build () {
        for(int i = 0; i <= H; i++) {
            for (int j = 1; j <= W; j++) data[i][j] += data[i][j - 1];
        }
        for (int j = 0; j <= W; j++) {
            for (int i = 1; i <= H; i++) data[i][j] += data[i - 1][j];
        }
        return data;
    }
};

int main() {
    setup_fast_io();

    ll n; cin >> n;
    ll H = 2000, W = 2000;
    Imos2D imos(H, W), id(H, W);
    rep(i, n) {
        ll r1, r2, c1, c2;
        cin >> r1 >> r2 >> c1 >> c2;
        r1--, c1--;
        imos.add(r1, r2, c1, c2, 1);
        id.add(r1, r2, c1, c2, i);
    }

    auto res_imos = imos.build();
    auto res_id = id.build();

    ll zero_sum = 0;
    vector<ll> only(n, 0);
    rep(r, H) {
        rep(c, W) {
            if (res_imos[r][c] == 0) {
                zero_sum++;
            }
            if (res_imos[r][c] == 1) {
                only[res_id[r][c]]++;
            }
        }
    }
    rep(i, n) {
        cout << zero_sum + only[i] << nl;
    }
    return 0;
}