// [prefix: spf]

// 前計算 O(NloglogN)
// 素因数分解 O(logN)
struct SPF {
    vector<ll> spf;

    SPF(ll n) : spf(n + 1) {
        for (ll i = 0; i <= n; i++) spf[i] = i;
        for (ll i = 2; i * i <= n; i++) {
            if (spf[i] == i) {
                for (ll j = i * i; j <= n; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
    }

    bool is_prime(ll x) {
        if (x <= 1) return false;
        return spf[x] == x;
    }

    map<ll, ll> factorize(ll x) {
        map<ll, ll> res;
        while (x > 1) {
            res[spf[x]]++;
            x /= spf[x];
        }
        return res;
    }
};