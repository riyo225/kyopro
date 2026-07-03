// [prefix: cycleancestors]

struct CycleAncestors {
    vector<ll> res;

    CycleAncestors(const Graph& G) {
        ll n = G.size();
        Graph rG(n);
        vector<ll> outdeg(n, 0);

        for (ll v = 0; v < n; v++) {
            for (ll nv : G[v]) {
                rG[nv].push_back(v);
                outdeg[v]++;
            }
        }

        queue<ll> que;
        for (ll i = 0; i < n; i++) {
            if (outdeg[i] == 0) que.push(i);
        }

        while (!que.empty()) {
            ll v = que.front();
            que.pop();
            for (ll nv : rG[v]) {
                outdeg[nv]--;
                if (outdeg[nv] == 0) que.push(nv);
            }
        }

        for (ll i = 0; i < n; i++) {
            if (outdeg[i] > 0) res.push_back(i);
        }
    }
};