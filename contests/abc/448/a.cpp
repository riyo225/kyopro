/**
 * @brief 遅延セグメント木
 * @tparam S 値の型
 * @tparam F 作用素(更新内容)の型
 */
template <typename S, typename F>
struct LazySegmentTree {
    int n, height;
    vector<S> tree;
    vector<F> lazy;

    using FX = function<S(S, S)>; // 1. マージ (op)
    using FA = function<S(F, S)>; // 2. 作用 (mapping)
    using FM = function<F(F, F)>; // 3. 合成 (composition)

    FX op; FA mapping; FM composition;
    S e; F id; // e: 値の単位元, id: 作用の単位元(何もしない)

    LazySegmentTree(int n_, FX op_, FA mapping_, FM composition_, S e_, F id_)
        : op(op_), mapping(mapping_), composition(composition_), e(e_), id(id_) {
        n = 1; height = 0;
        while (n < n_) n *= 2, height++;
        tree.assign(2 * n, e);
        lazy.assign(2 * n, id);
    }

    // 予約票を下へ伝搬させる (重要!)
    void push(int k) {
        if (lazy[k] == id) return;
        tree[2 * k] = mapping(lazy[k], tree[2 * k]);
        tree[2 * k + 1] = mapping(lazy[k], tree[2 * k + 1]);
        if (2 * k < n) lazy[2 * k] = composition(lazy[k], lazy[2 * k]);
        if (2 * k + 1 < n) lazy[2 * k + 1] = composition(lazy[k], lazy[2 * k + 1]);
        lazy[k] = id;
    }

    // 上から順に push して整合性を保つ
    void push_to_leaf(int k) {
        for (int i = height; i > 0; i--) push(k >> i);
    }

    // 区間更新 [l, r)
    void update(int l, int r, F x) {
        if (l == r) return;
        l += n; r += n;
        // 更新前にパス上の lazy を全部下ろす
        push_to_leaf(l); push_to_leaf(r - 1);

        int l0 = l, r0 = r;
        while (l < r) {
            if (l & 1) apply(l++, x);
            if (r & 1) apply(--r, x);
            l >>= 1; r >>= 1;
        }
        update_from_bottom(l0); update_from_bottom(r0 - 1);
    }

    // 区間クエリ [l, r)
    S query(int l, int r) {
        if (l == r) return e;
        l += n; r += n;
        push_to_leaf(l); push_to_leaf(r - 1);

        S res_l = e, res_r = e;
        while (l < r) {
            if (l & 1) res_l = op(res_l, tree[l++]);
            if (r & 1) res_r = op(tree[--r], res_r);
            l >>= 1; r >>= 1;
        }
        return op(res_l, res_r);
    }

private:
    void apply(int k, F x) {
        tree[k] = mapping(x, tree[k]);
        if (k < n) lazy[k] = composition(x, lazy[k]);
    }
    void update_from_bottom(int k) {
        while (k > 1) {
            k >>= 1;
            tree[k] = op(tree[2 * k], tree[2 * k + 1]);
        }
    }
};