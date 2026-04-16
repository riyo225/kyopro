// [prefix: bit]

template <typename T>
struct FenwickTree {
    ll n;
    vector<T> tree;

    FenwickTree(ll n) : n(n), tree(n + 1, 0) {}

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
}