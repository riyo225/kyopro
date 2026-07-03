// [prefix: wunionfind, wuf]

template <typename T>
struct WeightedUnionFind {
    ll n, group_count;
    vector<ll> par;
    vector<T> diff_weight;

    WeightedUnionFind(ll n) : n(n), par(n, -1), group_count(n), diff_weight(n, 0) {}

    ll root(ll x) {
        if (par[x] < 0) return x;
        ll r = root(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = r;
    }

    T weight(ll x) {
        root(x);
        return diff_weight[x];
    }

    T diff(ll x, ll y) {
        return weight(y) - weight(x);
    }

    bool unite(ll x, ll y, T w) {
        w += weight(x);
        w -= weight(y);
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) {
            swap(x, y);
            w = -w;
        }
        par[x] += par[y];
        par[y] = x;
        diff_weight[y] = w;
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