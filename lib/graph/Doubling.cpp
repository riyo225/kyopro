// [prefix: doubling]

// Doubling db(next_states);
struct Doubling {
    const ll LOG = 60;
    ll n;
    vector<vector<ll>> dp;

    Doubling(const vector<ll>& next_states) {
        n = next_states.size();
        dp.assign(LOG, vector<ll> (n, -1));

        for (ll i = 0; i < n; i++) {
            dp[0][i] = next_states[i];
        }

        for (ll k = 0; k < LOG - 1; k++) {
            for (ll v = 0; v < n; v++) {
                if (dp[k][v] == -1) {
                    dp[k + 1][v] = -1;
                }
                else {
                    dp[k + 1][v] = dp[k][dp[k][v]];
                }
            }
        }
    }

    ll query(ll v, ll k) {
        for (ll i = 0; i < LOG; i++) {
            if ((k >> i) & 1LL) {
                v = dp[i][v];
                if (v == -1) break;
            }
        }
        return v;
    }
};