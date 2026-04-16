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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define rrep(i, n) for (ll i = (ll)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) ((ll)(x).size())
#define nl "\n"
#define popcount(n) __builtin_popcountll(n);
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

struct mint {
    long long x;
    mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}

    mint operator-() const { return mint(-x); }

    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }

    mint operator+(const mint a) { return mint(*this) += a; }
    mint operator-(const mint a) { return mint(*this) -= a; }
    mint operator*(const mint a) { return mint(*this) *= a; }

    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    mint inv() const { return pow(MOD - 2); }

    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }

    bool operator==(const mint a) const { return x == a.x; }
    bool operator!=(const mint a) const { return x != a.x; }

    friend ostream& operator<<(ostream& os, const mint& m) { return os << m.x; }
    friend istream& operator>>(istream& is, mint& m) { long long t; is >> t; m = mint(t); return is; }
};

// S = 1 + r + r^2 + ... + r^(l-1) % MOD
mint geometric_sum(mint r, long long l) {
    if (l == 0) return 0;
    if (l == 1) return 1;

    if (l % 2 == 0) {
        return geometric_sum(r, l / 2) * (r.pow(l / 2) + 1);
    }
    else {
        return geometric_sum(r, l - 1) * r + 1;
    }
}


template <typename S, typename F>
struct LazySegmentTree {
    using FX = function<S(S, S)>; // 2つの値をマージする関数の型（op）
    using FA = function<S(F, S)>; // 値 S に更新操作 F を適用する（mapping）
    using FM = function<F(F, F)>; // 更新操作 F1 に F2 を合体させる（composition）

    int n; // 最下段のノード数
    int height;
    FX op; FA mapping; FM composition;
    S e; // op の単位元
    F id; // mapping の単位元
    vector<S> tree; // データを格納する配列（1-index）
    vector<F> lazy;

    LazySegmentTree(ll n_, FX op_, FA mapping_, FM composition_, S e_, F id_) : op(op_), mapping(mapping_), composition(composition_), e(e_), id(id_) {
        n = 1; height = 0;
        while (n < n_) n *= 2, height++;
        tree.assign(2 * n, e);
        lazy.assign(2 * n, id);
    }

    void set(int i, S x) { tree[i + n] = x; }

    void build(const vector<S> &v) {
        for (int i = 0; i < v.size(); i++) {
            tree[i + n] = v[i];
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = op(tree[2 * i], tree[2 * i + 1]);
        }
    }

    void push_to_leaf(int k) {
        for (int i = height; i > 0; i--) push(k >> i);
    }

    void update(int l, int r, F x) {
        l += n; r += n;
        push_to_leaf(l);
        push_to_leaf(r-1);

        int l_ = l; r_ = r;
        while (l < r) {
            if (l & 1) apply(l++, x);
            if (r & 1) apply(--r, x);
            l >>= 1; r >>= 1;
        }

        update_from_bottom(l_); update_from_bottom(r_ - 1);
    }

    S query(int l, int r) {
        S res_l = e; S res_r = e;
        l += n; r += n;
        push_to_leaf(l);
        push_to_leaf(r-1);

        while (l < r) {
            if (l & 1) res_l = op(res_l, tree[l++]);
            if (r & 1) res_r = op(tree[--r], res_r);

            l >>= 1; r >>= 1;
        }
        return op(res_l, res_r);
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
    void apply(int k, F x) {
        tree[k] = mapping(x, tree[k]);
        if (k < n) lazy[k] = composition(x, lazy[k]);
    }

    void push(int k) {
        if (lazy[k] == id) return;
        apply(2 * k, lazy[k]);
        apply(2 * k + 1, lazy[k]);
        lazy[k] = id;
    }

    void update_from_bottom(int k) {
        while (k > 1) {
            k >>= 1;
            tree[k] = op(tree[2 * k], tree[2 * k + 1]);
        }
    }

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

    ll n, q;
    cin >> n >> q;
    LazySegmentTree<char, char> seg(n, )

    return 0;
}