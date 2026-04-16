// [prefix: nextocc]

struct NextOccurrence {
    ll n;
    vector<vector<ll>> nxt;

    NextOccurrence(const string& s) : n(s.size()) {
        nxt.assign(n + 1, vector<ll> (26, n));
        for (ll i = n - 1; i >= 0; i--) {
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - 'a'] = i;
        }
    }

    ll next_pos(ll i, char c) const {
        if (i < 0) i = 0;
        if (i > n) return n;
        return nxt[i][c - 'a'];
    }

    bool is_subsequence(const string& t) const {
        ll cur = 0;
        for (char c : t) {
            cur = next_pos(cur, c);
            if (cur == n) return false;
            cur++;
        }
        return true;
    }

    bool contains(ll start, char c) const {
        return next_pos(start, c) < n;
    }
};