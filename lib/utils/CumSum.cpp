// [prefix: cumsum]

struct CumSum {
    ll n;
    vector<ll> pref, suff;
    
    CumSum(const vector<ll>& a) {
        n = a.size();
        // pref[i] は a[i] を含まない
        // suff[i] は a[i] を含む
        pref.assign(n + 1, 0);
        suff.assign(n + 1, 0);

        // pref[i] = a[0] + ... + a[i-1] : [0, i)
        for (ll i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        // suff[i] = a[i] + ... + a[n-1] : [i, n)
        for (ll i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] + a[i];
        }
    }

    ll sum_except(ll i) {
        return pref[i] + suff[i + 1];
    }

    ll query(ll l, ll r) {
        if (l >= r) return 0;
        return pref[r] - pref[l];
    }

    pair<ll, ll> split_at(ll i) {
        return {pref[i], suff[i]};
    }
};