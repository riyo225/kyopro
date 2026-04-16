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
const long double PI = acosl(-1.0L);
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

    ll max_right(ll l, const function<bool(T)> &check) {
        if (l == n) return n;
        l += n;
        T sum = e;
        do {
            while (l % 2 == 0) l >>= 1;
            if(!check(op(sum, tree[l]))) {
                while (l < n) {
                    l *= 2;
                    if (check(op(sum, tree[l]))) {
                        sum = op(sum, tree[l]);
                        l++;
                    }
                }
                return l - n;
            }
            sum = op(sum, tree[l]);
            l++;
        } while ((l & -l) != l);
        return n;
    }

    ll find_first(const function<bool(T)> &check) {
        T val = e;
        // 全体を見ても条件を満たさない場合
        if (!check(op(val, tree[1]))) return -1;
        
        ll i = 1;
        while (i < n) {
            T next_val = op(val, tree[2 * i]); // 左の子を足してみる
            if (check(next_val)) {
                // 左だけで条件を満たす -> 左へ
                i = 2 * i;
            } else {
                // 左だけでは足りない -> 右へ (valに左分を確定させる)
                val = next_val;
                i = 2 * i + 1;
            }
        }
        return i - n;
    }

    // ------------------------------------------------------------------
    // 全探索: find_all
    // 「条件 check_prune を満たす可能性のある枝を全て探索し、葉を列挙する」
    // 用途: 値が X 以上の要素を全て列挙するなど
    // ------------------------------------------------------------------
    void find_all(const function<bool(T)> &check_prune, vector<ll> &res) {
        find_all_recur(1, check_prune, res);
    }

private:
    void find_all_recur(ll k, const function<bool(T)> &check_prune, vector<ll> &res) {
        if (!check_prune(tree[k])) return; // 枝刈り
        if (k >= n) {
            res.push_back(k - n);
            return;
        }
        find_all_recur(2 * k, check_prune, res);
        find_all_recur(2 * k + 1, check_prune, res);
    }
};

int main() {
    setup_fast_io();

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    SegmentTree<ll> seg(n, [](ll a, ll b){ return max(a, b); }, -INF_LL);

    seg.update(0, a[0]);

    for (int i = 1; i < n; i++) {
        ll x = a[i] + seg.query(max(0LL, i - k), i);
        seg.update(i, x);
    }
    cout << seg.get(n-1) << nl;

    return 0;
}