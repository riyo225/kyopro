// [prefix: scc]

struct SCC {
    ll n;
    vector<vector<ll>> G, rG;
    vector<ll> order;
    vector<bool> used;
    vector<ll> comp;
    vector<vector<ll>> scc;
    vector<vector<ll>> dag;

    SCC(ll _n) : n(_n), G(_n), rG(_n), used(_n, false), comp(_n, -1) {}

    void add(ll u, ll v) {
        G[u].push_back(v);
        rG[v].push_back(u);
    }

    void dfs(ll v) {
        used[v] = true;
        for (ll nv : G[v]) {
            if (!used[nv]) dfs(nv);
        }
        order.push_back(v);
    }

    void rdfs(ll v, ll k) {
        comp[v] = k;
        scc.back().push_back(v);
        for (ll nv : rG[v]) {
            if (comp[nv] == -1) rdfs(nv, k);
        }
    }

    ll build() {
        for (ll i = 0; i < n; i++) {
            if (!used[i]) dfs(i);
        }

        ll k = 0;
        for (ll i = order.size() - 1; i >= 0; i--) {
            ll v = order[i];
            if (comp[v] == -1) {
                scc.push_back(vector<ll>());
                rdfs(v, k);
                k++;
            }
        }

        dag.resize(k);
        for (ll u = 0; u < n; u++) {
            for (ll v : G[u]) {
                ll cu = comp[u];
                ll cv = comp[v];
                if (cu != cv) {
                    dag[cu].push_back(cv);
                }
            }
        }

        for (ll i = 0; i < k; i++) {
            sort(all(dag[i]));
            dag[i].erase(unique(all(dag[i])), dag[i].end());
        }

        return k;
    }
};