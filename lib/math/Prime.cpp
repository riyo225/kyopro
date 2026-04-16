// [prefix: prime]

// 素数判定
bool is_prime(ll n) {
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 素因数分解
map<ll, ll> prime_factorize(ll n) {
    // {素因数, 指数}
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; i++) {
        while(n % i == 0) { res[i]++; n /= i; }
    }
    if (n > 1) res[n]++;
    return res;
}

// 約数列挙
vector<ll> get_divisors(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}