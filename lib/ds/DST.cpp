// [prefix: DST]

template <typename T>
struct DST {
    vector<vector<T>> table;
    ll LOG = 0;

    DST(vector<T>& a) {
        ll n = a.size();
        while ((1LL << LOG) < n) LOG++;
        ll N = (1LL << LOG);
        a.resize(N);

        table.assign(LOG, vector<ll> (N, 0));
        for (ll i = 0; i < n; i++) {
            table[0][i] = a[i];
        }

        for (ll k = LOG-1; k >= 0; k--) {
        for (ll s = (1 << k); s < n; s += (1 << (k+1))) {
                table[k][s] = a[s];
                if (s-1 >= 0) table[k][s-1] = a[s-1];
                for (ll i = 1; i < (1 << k); i++) {
                    if (s + i < n) table[k][s+i] = table[k][s+i-1] + a[s+i];
                    if (s - i - 1 >= 0) table[k][s-i-1] = table[k][s-i] + a[s-i-1];
                }
            }
        }
    }

    T query(ll l, ll r) {
        if (r <= l) return 0;
        if (r - l == 1) return table[0][l];
        ll x = l ^ (r - 1);
        ll k = __lg(x);
        return table[k][l] + table[k][r-1];
    }
};