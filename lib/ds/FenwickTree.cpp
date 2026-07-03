// [prefix: bit, fenwicktree]

template <typename T>
struct BIT {
    ll n;
    vector<T> tree;

    BIT(ll n) : n(n), tree(n + 1, 0) {}

    void build(const vector<T>& a) {
        for (ll i = 0; i < n; i++) tree[i + 1] = a[i];
        for (ll i = 1; i <= n; i++) {
            ll j = i + (i & -i);
            if (j <= n) tree[j] += tree[i];
        }
    }

    void add(ll i, T x) {
        for (i++; i <= n; i += (i & -i)) tree[i] += x;
    }

    void update(ll i, T x) {
        add(i, x - get(i));
    }

    T query(ll i) {
        T s = 0;
        for (; i > 0; i -= i & -i) s += tree[i];
        return s;
    }

    T range_query(ll l, ll r) {
        if (l >= r) return 0;
        return query(r) - query(l);
    }

    T get(ll i) {
        return query(i + 1) - query(i);
    }

    ll lower_bound(T w) {
        if (w <= 0) return 0;
        ll x = 0;
        ll k = 1;
        while (k <= n) k *= 2;
        for (; k > 0; k /= 2) {
            if (x + k <= n && tree[x + k] < w) {
                w -= tree[x + k];
                x += k;
            }
        }
        return x;
    }
};