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

// Doubling db(next_states);
struct Doubling {
    const ll LOG = 60;
    ll n;
    vector<vector<ll>> dp;

    Doubling(const vector<ll>& next_states) {
        n = next_states.size();
        dp.assign(LOG, vector<ll> (n, -1));

        for (ll i = 0; i < n; i++) {
            dp[0][i] = next_states[i];
        }

        for (ll k = 0; k < LOG - 1; k++) {
            for (ll v = 0; v < n; v++) {
                if (dp[k][v] == -1) {
                    dp[k + 1][v] = -1;
                }
                else {
                    dp[k + 1][v] = dp[k][dp[k][v]];
                }
            }
        }
    }

    // v からぴったり k 回ジャンプした先の頂点を返す
    ll jump_exact(ll v, ll x) {
        for (ll k = 0; k < LOG; k++) {
            if ((x >> k) & 1LL) {
                v = dp[k][v];
                if (v == -1) break;
            }
        }
        return v;
    }

    // 限界までジャンプをし、{ 回数, 到達地点 } を返す
    pll jump_limit(ll start, ll limit) {
        ll cur = start;
        ll ans = 0;
        for (int k = LOG - 1; k >= 0; k--) {
            if (dp[k][cur] != -1 && dp[k][cur] <= limit) {
                ans += (1LL << k);
                cur = dp[k][cur];
            }
        }
        return {ans, cur};
    }
};

mint dp[1009][19][19][19];

int main() {
    setup_fast_io();

    ll n; cin >> n;
    string a, b, c; cin >> a >> b >> c;
    ll A = sz(a), B = sz(b), C = sz(c);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= A; j++) {
            for (int k = 0; k <= B; k++) {
                for (int l = 0; l <= C; l++) {
                    dp[i][j][k][l] = 0;
                }
            }
        }
    }
    dp[0][0][0][0] = 1;

    rep(i, n) {
        for (int j = 0; j < A; j++) {
            for (int k = 0; k < B; k++) {
                for (int l = 0; l < C; l++) {
                    if (dp[i][j][k][l] == 0) continue;
                    for (char s = 'a'; s <= 'z'; s++) {
                        ll nj = j;
                        if (j < A && s == a[j]) nj++;
                        ll nk = k;
                        if (k < B && s == b[k]) nk++;
                        ll Nl = l;
                        if (l < C && s == c[l]) Nl++;
                        if (nj == A || nk == B || Nl == C) continue;

                        dp[i+1][nj][nk][Nl] += dp[i][j][k][l];
                    }
                }
            }
        }
    }

    mint ans = 0;
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < B; j++) {
            for (int k = 0; k < C; k++) {
                ans += dp[n][i][j][k];
            }
        }
    }
    cout << ans << nl;


    return 0;
}