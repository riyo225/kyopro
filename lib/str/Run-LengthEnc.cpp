// [prefix: rle]

namespace RLE {
    template <typename V>
    struct Node {
        V val;
        ll start;
        ll len;
    };

    template <typename T>
    auto encode (const T& s) {
        using V = typename T::value_type;
        vector<Node<V>> res;
        ll n = s.size();
        for (ll l = 0; l < n; ) {
            ll r = l + 1;
            while (r < n && s[l] == s[r]) r++;
            res.emplace_back({s[l], l, r - l});
            l = r;
        }
        return res;
    }

    template <typename T, typename V = typename T::value_type>
    T decode(const vector<Node<V>>& encoded) {
        T res;
        for (const auto& node : encoded) {
            for (ll i = 0; i < node.len; i++) {
                res.push_back(node.val);
            }
        }
        return res;
    }

    template <typename V>
    auto find_block(const vector<Node<V>>& encoded, ll k) {
        auto it = upper_bound(all(encoded), k, [](ll val, const Node<V>& node) {
            return val < node.start;
        });
        return prev(it);
    }
}