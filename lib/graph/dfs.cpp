vector<bool> seen(n, false);
seen[0] = true;

auto dfs = [&](auto self, ll v) -> void {
    seen[v] = true;

    for (ll nv : graph[v]) {
        if (seen[nv]) continue;
        self(self, nv);
    }
};

dfs(dfs, 0);