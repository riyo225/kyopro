// [prefix: uf]

struct UnionFind {
    ll n, group_count;
    vector<ll> par;

    UnionFind(ll n) : n(n), par(n, -1), group_count(n) {}

    ll root(ll x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    bool unite(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        group_count--;
        return true;
    }

    bool same(ll x, ll y) { return root(x) == root(y); }

    ll size(ll x) { return -par[root(x)]; }

    vector<vector<ll>> groups() {
        vector<vector<ll>> res(n);
        for (ll i = 0; i < n; i++) res[root(i)].push_back(i);
        res.erase(
            remove_if(res.begin(), res.end(), [](const vector<ll>& v) { return v.empty(); }),
            res.end()
        );
        return res;
    }
};