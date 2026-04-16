// [prefix: compressor]
// Compressor<type> comp;
template <typename T>
struct Compressor {
    vector<T> vals;

    Compressor(const vector<T>& a) {
        vals = a;
        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());
    }

    // 元の値 -> 圧縮後の座標
    ll get(const T& x) const {
        return lower_bound(all(vals), x) - vals.begin();
    }

    vector<ll> get_compressed(const vector<T>& a) const {
        vector<ll> res(a.size());
        for (ll i = 0; i < a.size(); i++) res[i] = get(a[i]);
        return res;
    }

    // 圧縮後の座標 -> 元の値
    T inv(ll i) const { return vals[i]; }

    ll size() const { return vals.size(); }
};