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
template <class Monoid>
struct DualSegmentTree {
    using T = typename Monoid::Type;
    ll n;
    vector<T> tree;

    DualSegmentTree(ll n_) {
        n = 1;
        while (n < n_) n *= 2;
        tree.assign(2 * n, Monoid::e());
    }

    void apply(ll l, ll r, T x) {
        l += n; r += n;
        while (l < r) {
            if (l % 2 == 1) {
                tree[l] = Monoid::op(tree[l], x);
                l++;
            }
            if (r % 2 == 1) {
                r--;
                tree[r] = Monoid::op(x, tree[r]);
            }
            l /= 2; r /= 2;
        }
    }

    T get(ll i) {
        i += n;
        T res = tree[i];
        while (i > 1) {
            i /= 2;
            res = Monoid::op(res, tree[i]);
        }
        return res;
    }
};

struct mint {
    static ll& mod() { static ll m = 998244353; return m; }
    static void set_mod(ll m) { mod() = m; }

    ll x;
    mint(ll x = 0) : x((x % mod() + mod()) % mod()) {}

    mint operator-() const { return mint(-x); }

    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod()) x -= mod();
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod() - a.x) >= mod()) x -= mod();
        return *this;
    }
    mint& operator*=(const mint a) {
        x = (ll)((__int128)x * a.x % mod());
        return *this;
    }

    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }

    mint pow(ll t) const {
        mint res = 1, a = *this;
        while (t > 0) {
            if (t & 1) res *= a;
            a *= a;
            t >>= 1;
        }
        return res;
    }

    mint inv() const {
        ll a = x, b = mod(), u = 1, v = 0;
        while (b) {
            ll t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        return mint(u);
    }

    // n * (a + l) / 2
    static mint arithmetic_sum(mint a, mint d, ll n) {
        if (n <= 0) return 0;
        mint last = a + mint(n - 1) * d;
        return mint(n) * (a + last) / 2;
    }

    // 1 + r + r^2 + ... + r^(l-1)
    static mint geometric_sum(mint r, ll l) {
        if (l == 0) return 0;
        if (l == 1) return 1;
        if (l % 2 == 0) return geometric_sum(r, l / 2) * (r.pow(l / 2) + 1);
        else return geometric_sum(r, l - 1) * r + 1;
    }

    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }

    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    mint operator++(int) { mint res = *this; ++*this; return res; }
    mint operator--(int) { mint res = *this; --*this; return res; }

    bool operator==(const mint a) const { return x == a.x; }
    bool operator!=(const mint a) const { return x != a.x; }

    friend ostream& operator<<(ostream& os, const mint& m) { return os << m.x; }
    friend istream& operator>>(istream& is, mint& m) { ll t; is >> t; m = mint(t); return is; }
};

// Combination comb(n);
struct Combination {
    vector<mint> fact, ifact;
    Combination(ll n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (ll i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (ll i = n - 1; i >= 0; i--) ifact[i] = ifact[i + 1] * (i + 1);
    }
    mint nCr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * ifact[r] * ifact[n - r];
    }
    mint nPr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * ifact[n - r];
    }
    mint nHr(ll n, ll r) {
        if (n == 0 && r == 0) return 1;
        return nCr(n + r - 1, r);
    }
};

int main() {
    setup_fast_io();

    ll n; cin >> n;
    DualSegmentTree<MonoidSum<ll>> cntA(n), cntB(n), covered(n);
    rep(i, n) {
        ll l, r; cin >> l >> r;
        cntA.apply(l, r + 1, 1);
        ll bl = n - r, br = n - l;
        cntB.apply(bl, br + 1, 1);

        if (max(l, bl) <= min(r, br)) {
            covered.apply(min(l, bl), max(r, br) + 1, 1);
        } else {
            covered.apply(l, r + 1, 1);
            covered.apply(bl, br + 1, 1);
        }
    }

    Combination comb(n+1);

    mint ans = 0;
    for (int k = 1; k < n; k++) {
        if (covered.get(k) < n) continue;
        ll onlyA = n - cntB.get(k);
        ll both = cntA.get(k) + cntB.get(k) - n;

        if (k - onlyA >= 0 && k - onlyA <= both) ans += comb.nCr(both, k - onlyA);
    }

    cout << ans << nl;

    return 0;
}