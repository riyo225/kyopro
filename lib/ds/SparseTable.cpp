// [prefix: sparse]

template <typename T>
struct SparseTable {
    vector<vector<T>> table;

    SparseTable(const vector<T>& a) {
        ll n = a.size();
        ll LOG = __lg(n) + 1;

        table.assign(LOG, vector<T> (n));
        for (ll i = 0; i < n; i++) table[0][i] = a[i];

        for (ll k = 1; k < LOG; k++) {
            for (ll i = 0; i + (1LL << k) <= n; i++) {
                table[k][i] = min(table[k - 1][i], table[k - 1][i + (1LL << (k - 1))]);
            }
        }
    }

    // [l, r) の最小値を返す
    T query(ll l, ll r) {
        if (l >= r) return 2e18;
        ll k = __lg(r - l);
        return min(table[k][l], table[k][r - (1LL << k)]);
    }
};