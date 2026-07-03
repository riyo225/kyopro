vector<ll> memo(n, -1);

auto dfs = [&](auto self, ll v) -> ll {
    // memo の確認
    if (memo[v] != -1) return memo[v];

    // 更新値の計算
    ll res = 0;
    for (auto nv : graph[v]) {
        chmax(res, self(self, nv) + 1);
    }

    // memo の更新
    return memo[v] = res;
};