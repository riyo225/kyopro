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

template <typename T>
struct MonoidMin {
    using Type = T;
    static T op(T a, T b) { return min(a, b); }
    static T e() { return numeric_limits<T>::max() / 2; } 
};

template <typename T>
struct MonoidMax {
    using Type = T;
    static T op(T a, T b) { return max(a, b); }
    static T e() { return numeric_limits<T>::lowest() / 2; } 
};

template <typename T>
struct MonoidSum {
    using Type = T;
    static T op(T a, T b) { return a + b; }
    static T e() { return T(0); } 
};

template <typename T>
struct MonoidXor {
    using Type = T;
    static T op(T a, T b) { return a ^ b; }
    static T e() { return T(0); } 
};

// f(x) = ax + b
struct Affine { ll a, b; };
template <ll MOD = 998244353> struct MonoidAffine {
    using Type = Affine;
    static Type op(Type l, Type r) {
        return { (r.a * l.a) % MOD, (r.a * l.b + r.b) % MOD };
    }
    static Type e() { return {1, 0}; }
};

// これより下わからない
template <typename T>
struct MonoidGCD {
    using Type = T;
    static T op(T a, T b) { return std::gcd(a, b); }
    static T e() { return 0; }
};

// これより下わからない
// Rolling Hash (文字列一致判定など)
struct HashNode { ll hash, p_pow; };
template <ll MOD = 1000000007, ll BASE = 10007> struct MonoidRollingHash {
    using Type = HashNode;
    static Type op(Type l, Type r) {
        return { (l.hash * r.p_pow + r.hash) % MOD, (l.p_pow * r.p_pow) % MOD };
    }
    static Type e() { return {0, 1}; }
};

// 最大連続部分和 (GSS)
struct GSSNode { ll sum, l_max, r_max, res; };
struct MonoidGSS {
    using Type = GSSNode;
    static Type op(Type l, Type r) {
        return {
            l.sum + r.sum,
            max(l.l_max, l.sum + r.l_max),
            max(r.r_max, r.sum + l.r_max),
            max({l.res, r.res, l.r_max + r.l_max})
        };
    }
    static Type e() { return {0, -INF, -INF, -INF}; }
};

// 2x2 行列積
template <typename T, ll MOD = 998244353> struct MonoidMatrix22 {
    struct Matrix { T a, b, c, d; };
    using Type = Matrix;
    static Type op(Type l, Type r) {
        return {
            (l.a * r.a + l.b * r.c) % MOD,
            (l.a * r.b + l.b * r.d) % MOD,
            (l.c * r.a + l.d * r.c) % MOD,
            (l.c * r.b + l.d * r.d) % MOD
        };
    }
    static Type e() { return {1, 0, 0, 1}; }
};
// SegmentTree<Monoid<ll>> seg(n);
// SegmentTree<MonoidSum<mint>> seg(n);
// SegmentTree<MonoidAffine<998244353>> seg(n);
template <class Monoid>
struct SegmentTree {
    using T = typename Monoid::Type;
    ll n;
    vector<T> tree;

    SegmentTree(ll n_) {
        n = 1;
        while (n < n_) n *= 2;
        tree.assign(2 * n, Monoid::e());
    }

    void build(const vector<T>& a) {
        for (ll i = 0; i < a.size(); i++) tree[i + n] = a[i];
        for (ll i = n-1; i > 0; i--) tree[i] = Monoid::op(tree[2 * i], tree[2 * i + 1]);
    }

    void update(ll i, T x) {
        i += n;
        tree[i] = x;
        while (i > 1) {
            i >>= 1;
            tree[i] = Monoid::op(tree[2 * i], tree[2 * i + 1]);
        }
    }

    T query(ll l, ll r) {
        T res_l = Monoid::e();
        T res_r = Monoid::e();
        l += n; r += n;
        while (l < r) {
            if (l & 1) res_l = Monoid::op(res_l, tree[l++]);
            if (r & 1) res_r = Monoid::op(tree[--r], res_r);
            l >>= 1; r >>= 1;
        }
        return Monoid::op(res_l, res_r);
    }

    T get(ll i) { return tree[i + n]; }
    T operator[](ll i) { return tree[i + n]; }
};

int main() {
    setup_fast_io();

    ll n, q; cin >> n >> q;
    vll a(n); cin >> a;

    SegmentTree<MonoidSum<ll>> seg(n);
    seg.build(a);

    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll x; cin >> x; x--;
            ll y = seg.get(x);
            seg.update(x, seg.get(x+1));
            seg.update(x+1, y);
        }
        else {
            ll l, r; cin >> l >> r; l--;
            cout << seg.query(l, r) << nl;
        }
    }

    return 0;
}