#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 2e9;
const ll INF_LL = 9e18;
const int MOD = 1000000007; // 998244353
const double PI = acos(-1);
// const string ALPHA_LOWER = "abcdefghijklmnopqrstuvwxyz"; // 必要ならコメント解除
// const string ALPHA_UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 必要ならコメント解除
const int DX8[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int DY8[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int DX4[] = {1, 0, -1, 0};
const int DY4[] = {0, 1, 0, -1};
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

// デバッグ出力を有効にするには、以下の行のコメントアウトを解除してください。
// #define DEBUG
#ifdef DEBUG
    #define debug(x) cerr << #x << ": " << (x) << endl
    #define debug_vec(vec) { cerr << #vec << ": "; for(const auto& elem : vec) cerr << elem << " "; cerr << endl; }
    #define debug_pair(p) cerr << #p << ": (" << (p).first << ", " << (p).second << ")" << endl
    #define debug_2d_vec(vec2d) { cerr << #vec2d << ":" << endl; for(const auto& row : vec2d) { cerr << "  "; for(const auto& elem : row) cerr << elem << " "; cerr << endl; } }
    // mapのデバッグ出力は必要性が低いが、もし使うなら以下を使用
    // #define debug_map(m) { cerr << #m << ": "; for(const auto& [key, val] : m) cerr << "(" << key << ":" << val << ") "; cerr << endl; }
#else
    #define debug(x)
    #define debug_vec(vec)
    #define debug_pair(p)
    #define debug_2d_vec(vec2d)
    // #define debug_map(m)
#endif

void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);
}

struct Edge {
    ll to;
    ll cost;
};
// using Graph = vector<vector<ll>>;
// using Graph = vector<vector<Edge>>;

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

template <typename T>
struct SegmentTree {
    using FX = function<T(T, T)>; // 2つの値をマージする関数の型
    int n; // 最下段のノード数
    FX op; // 演算関数
    T e; // 単位元
    vector<T> tree; // データを格納する配列（1-index）

    SegmentTree(ll n_, FX op_, T e_) : op(op_), e(e_) {
        n = 1;
        while (n < n_) n *= 2;
        tree.assign(2 * n, e);
    }

    void build(const vector<T> &v) {
        for (int i = 0; i < v.size(); i++) {
            tree[i+n] = v[i];
        }
        for (int i = n-1; i > 0; i--) {
            tree[i] = op(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void update(ll i, T x) {
        i += n;
        tree[i] = x;
        while (i > 1) {
            i >>= 1;
            tree[i] = op(tree[2 * i], tree[2 * i + 1]);
        }
    }

    T query(ll l, ll r) {
        T res = e;
        l += n;
        r += n;

        while (l < r) {
            if (l & 1) res = op(res, tree[l++]);
            if (r & 1) res = op(res, tree[--r]);

            l >>= 1;
            r >>= 1;
        }
        return res;
    }

    T get(ll i) {
        return tree[i + n];
    }
};

int main() {
    setup_fast_io();

    ll M = 998244353;
    ll t;
    cin >> t;
    while (t > 0) {
        ll sum = 1;
        ll n;
        cin >> n;
        vector<ll> a(n);
        rep(i, n) {
            cin >> a[i];
        }

        vector<ll> b(2*n);
        rep(i, n) {
            b[i] = a[i];
            b[i+n] = a[i];
        }

        SegmentTree<ll> seg(2*n, [&](ll a, ll b) { return a / GCD(a, b) * b; }, 1);

        seg.build(b);

        ll l = 1;
        ll r = n+1;
        rep(i, n) {
            cout << seg.query(l+i, r+i) % M << " ";
        }
        cout << nl;
    }


    return 0;
}