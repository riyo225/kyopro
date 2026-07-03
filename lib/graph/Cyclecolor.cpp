// [prefix: colorcycle, cyclecolor]

vector<int> color(n, 0);
bool has_cycle = false;
auto dfs = [&](auto self, ll v) -> void {
    color[v] = 1;

    for (auto nv : graph[v]) {
        if (color[nv] == 1) {
            has_cycle = true;
            return;
        }
        if (color[nv] == 0) {
            self(self, nv);
        }
    }

    color[v] = 2;
};

for (int i = 0; i < n; i++) {
    if (color[i] == 0) {
        dfs(dfs, i);
    }
}

yes(has_cycle);