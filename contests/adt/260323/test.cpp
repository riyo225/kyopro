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

#define DEBUG
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

template <typename T>
struct CumSum {
    long long n;
    // pref[i] は a[i] を含まない
    // suff[i] は a[i] を含む
    vector<T> pref, suff;

    CumSum(const vector<T> &a) {
        n = a.size();
        pref.assign(n + 1, 0);
        suff.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] + a[i];
        }
    }

    T query(long long l, long long r) {
        if (l >= r) return 0;
        return pref[r] - pref[l];
    }

    T sum_except(long long i) {
        if (i < 0 || i >= n) return 0;
        return pref[i] + suff[i + 1];
    }

    pair<T, T> split_at(long long i) {
        return {pref[i], suff[i]};
    }
};

template <typename T>
struct CumSum2D {
    long long H, W;
    vector<vector<T>> pref;

    CumSum2D(const vector<vector<T>>& a) {
        H = a.size();
        W = (H > 0) ? a[0].size() : 0;
        pref.assign(H + 1, vector<T> (W + 1, 0));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                pref[i + 1][j + 1] = pref[i][j + 1] + pref[j + 1][i] - pref[i][j] + a[i][j];
            }
        }
    }

    T query(long long h1, long long w1, long long h2, long long w2) {
        if (h1 >= h2 || w1 >= w2) return 0;
        return pref[h2][w2] - pref[h1][w2] - pref[h2][w1] + pref[h1][w1];
    }
};

int main() {
    setup_fast_io();

    ll n = 5;
    vector<ll> a = {1, 2, 4, 5, 6};

    CumSum cs(a);

    for (int i = 0; i <= n; i++) {
        debug_pair(cs.split_at(i));
    }

    return 0;
}