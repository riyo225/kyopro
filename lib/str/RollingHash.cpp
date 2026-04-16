// [prefix: rollhash, rh]

struct RollingHash {
    static const ull MOD = (1ULL << 61) - 1;
    vector<ull> hash, power;

    static inline ull mul(ull a, ull b) {
        __uint128_t c = (__uint128_t)a * b;
        c = (c >> 61) + (c & MOD);
        if (c >= MOD) c -= MOD;
        return (ull)c;
    }

    RollingHash(const string &s, ull base) {
        ll n = s.size();
        hash.assign(n + 1, 0);
        power.assign(n + 1, 1);
        for (ll i = 0; i < n; i++) {
            hash[i + 1] = mul(hash[i], base) + s[i];
            if (hash[i + 1] >= MOD) hash[i + 1] -= MOD;
            power[i + 1] = mul(power[i], base);
        }
    }

    ull get(ll l, ll r) {
        ull res = hash[r] + MOD - mul(hash[l], power[r - l]);
        if (res >= MOD) res -= MOD;
        return res;
    }
};

ull generate_base() {
    mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<ull> rand(256, RollingHash::MOD - 1);
    return rand(engine);
}