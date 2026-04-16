// [prefix: imos]

template <typename T>
struct Imos {
    ll n;
    vector<T> data;
    Imos(ll n) : n(n), data(n + 1, T(0)) {}

    // [l, r) に v を加算
    void add(ll l, ll r, T v) {
        if (l < 0 || r > N || l >= r) return;
        data[l] += v;
        data[r] -= v;
    }

    vector<T> build() {
        vector<T> res(n);
        T cur = T(0);
        for (int i = 0; i < n; i++) {
            cur += data[i];
            res[i] = cur;
        }
        return res;
    }
};