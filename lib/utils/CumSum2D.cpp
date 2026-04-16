// [prefix: cumsum2d]

struct CumSum2D {
    ll h, w;
    vector<vector<ll>> s;

    CumSum2D(const vector<vector<ll>>& a) {
        if (a.empty()) return;
        h = a.size(); w = a[0].size();

        s.assign(h + 1, vector<ll> (w + 1, 0));

        for (ll i = 0; i < h; i++) {
            for (ll j = 0; j < w; j++) {
                s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];
            }
        }
    }

    ll query(ll x1, ll y1, ll x2, ll y2) {
        if (x1 >= x2 || y1 >= y2) return 0;
        return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
    }
}