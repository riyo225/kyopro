// [prefix: rle]

template <typename T>
struct RLE {
    using V = typename T::value_type;
    struct Node {
        V val;
        ll len;
        ll start;
    };

    vector<Node> blocks;
    ll total

    RLE(const T& s) {
        prefix_len.push_back(0);
        for (ll l = 0, n = s.size(); l < n; ) {
            ll r = l + 1;
            while (r < n && s[l] == s[r]) r++;
            blocks.push_back({s[l], r - l});
            prefix_len.push_back(prefix_len.back() + (r - l));
            l = r;
        }
    }

    auto begin() const { return blocks.begin(); }
    auto end() const { return blocks.end(); }

    T decode() const {
        T res;
        res.reserve(prefix_len.back());
        for (const auto& [val, len] : blocks) {
            for (int i = 0; i < len; i++) res.push_back(val);
        }
        return res;
    }

    V get_val_at(ll k) const {
        assert(0 <= k && k < prefix_len.back());

        auto it = upper_bound(all(prefix_len), k);
        ll idx = distance(prefix_len.begin(), prev(it));

        return blocks[idx].val;
    }
};