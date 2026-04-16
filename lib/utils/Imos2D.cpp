// [prefix: imos2d]

struct Imos2D {
    ll H, W;
    vector<vector<ll>> data;
    bool is_build = false;

    Imos2D(ll h, ll w) : H(h), W(w), data(h + 2, vector<ll> (w + 2, 0)) {}

    // [r1, r2) x [c1, c2) に v を加算
    void add (ll r1, ll r2, ll c1, ll c2, ll v) {
        r1 = max(0LL, r1); c1 = max(0LL, c1);
        r2 = min(H, r2); c2 = min(W, c2);
        if (r1 >= r2 || c1 >= c2) return;

        data[r1][c1] += v;
        data[r1][c2] -= v;
        data[r2][c1] -= v;
        data[r2][c2] += v;
    }

    vector<vector<T>>& build () {
        if (is_build) return data;
        for(ll i = 0; i <= H; i++) {
            for (ll j = 1; j <= W; j++) data[i][j] += data[i][j - 1];
        }
        for (ll j = 0; j <= W; j++) {
            for (ll i = 1; i <= H; i++) data[i][j] += data[i - 1][j];
        }
        return data;
    }

    long long get(ll r, ll c) {
        return data[r][c];
    }
};