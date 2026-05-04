// [prefix: dualsegmenttree]

template <class Monoid>
struct DualSegmentTree {
    using T = typename Monoid::Type;
    ll n;
    vector<T> tree;

    DualSegmentTree(ll n_) {
        n = 1;
        while (n < n_) n *= 2;
        tree.assign(2 * n, Monoid::e());
    }

    void apply(ll l, ll r, T x) {
        l += n; r += n;
        while (l < r) {
            if (l % 2 == 1) {
                tree[l] = Monoid::op(tree[l], x);
                l++;
            }
            if (r % 2 == 1) {
                r--;
                tree[r] = Monoid::op(x, tree[r]);
            }
            l /= 2; r /= 2;
        }
    }

    T get(ll i) {
        i += n;
        T res = tree[i];
        while (i > 1) {
            i /= 2;
            res = Monoid::op(res, tree[i]);
        }
        return res;
    }
};