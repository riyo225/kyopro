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
const int MOD = 1000000007;
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

struct mint {
    static long long& mod() { static long long m = 998244353; return m; }
    static void set_mod(long long m) { mod() = m; }

    long long x;
    mint(long long x = 0) : x((x % mod() + mod()) % mod()) {}

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
        x = (long long)((__int128)x * a.x % mod());
        return *this;
    }

    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }

    mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    mint inv() const {
        long long a = x, b = mod(), u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        return mint(u);
    }

    static mint arithmetic_sum(mint a, mint d, long long n) {
        if (n <= 0) return 0;
        mint first = a;
        mint last = a + mint(n - 1) * d;
        return mint(n) * (first + last) / 2;
    }

    // S = 1 + r + r^2 + ... + r^(l-1) % MOD
    static mint geometric_sum(mint r, long long l) {
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
    friend istream& operator>>(istream& is, mint& m) { long long t; is >> t; m = mint(t); return is; }
};

struct Combination {
    vector<mint> fact, inv;
    Combination(int n) : fact(n + 1), inv(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        inv[n] = fact[n].inv();
        for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1);
    }
    mint nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * inv[r] * inv[n - r];
    }
};

int main() {
    setup_fast_io();

    string s;
    cin >> s;
    mint::set_mod(MOD);

    vector<mint> dp(9, 0);
    string t = "chokudai";
    dp[0] = 1;
    for (auto c : s) {
        rrep(i, sz(t)) {
            if (c == t[i]) {
                dp[i+1] += dp[i];
            }
        }
    }
    cout << dp[8] << nl;

    return 0;
}