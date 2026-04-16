// [prefix: mint]

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