#include <bits/stdc++.h>
using namespace std;

#define long long ll

using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(const Graph& graph, int v) {
    seen[v] = true;

    for (auto nv : graph[v]) {
        if (seen[nv]) continue;
        dfs(graph, nv);
    }
}

int main() {
    // 頂点数と辺数
    int n, m;
    cin >> n >> m;

    // グラフ
    Graph graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        // a--; b--;

        graph[a].push_back(b);
        // graph[b].push_back(a);
    }

    seen.assign(n, false);
    // O(N+M)
    dfs(graph, 0);
}