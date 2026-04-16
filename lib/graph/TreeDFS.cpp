auto dfs = [&](auto self, ll v, ll p) -> void {
    
    // 行きがけ

    for (ll nv : graph[v]) {
        if (nv == p) continue;
        self(self, nv, v);
    }

    // 帰りがけ
}