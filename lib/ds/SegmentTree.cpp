// [prefix: st]

// SegmentTree<Monoid<ll>> seg(n);
// SegmentTree<MonoidSum<mint>> seg(n);
// SegmentTree<MonoidAffine<998244353>> seg(n);
template <class Monoid>
struct SegmentTree {
    using T = typename Monoid::Type;
    ll n;
    vector<T> tree;

    SegmentTree(ll n_) {
        n = 1;
        while (n < n_) n *= 2;
        tree.assign(2 * n, Monoid::e());
    }

    void build(const vector<T>& a) {
        for (ll i = 0; i < a.size(); i++) tree[i + n] = a[i];
        for (ll i = n-1; i > 0; i--) tree[i] = Monoid::op(tree[2 * i], tree[2 * i + 1]);
    }

    void update(ll i, T x) {
        i += n;
        tree[i] = x;
        while (i > 1) {
            i >>= 1;
            tree[i] = Monoid::op(tree[2 * i], tree[2 * i + 1]);
        }
    }

    T query(ll l, ll r) {
        T res_l = Monoid::e();
        T res_r = Monoid::e();
        l += n; r += n;
        while (l < r) {
            if (l & 1) res_l = Monoid::op(res_l, tree[l++]);
            if (r & 1) res_r = Monoid::op(tree[--r], res_r);
            l >>= 1; r >>= 1;
        }
        return Monoid::op(res_l, res_r);
    }

    T get(ll i) { return tree[i + n]; }
    T operator[](ll i) { return tree[i + n]; }
};