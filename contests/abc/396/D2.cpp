#include <bits/stdc++.h>
using namespace std;

#define ll long long
constexpr ll INF = (1LL << 60);

struct Edge
{
    int to;
    ll cost;
};

using Graph = vector<vector<Edge>>;

vector<bool> seen;
ll ans = INF;
void dfs(const Graph& graph, int v, int n, ll x) {
    seen[v] = true;

    for (auto edge : graph[v]) {
        int nv = edge.to;
        ll w = edge.cost;

        ll nx = x ^ w;

        if (seen[nv]) continue;

        // cout << "v: " << v << " nv: " << nv << " x: " << x << " w: " << w << " nx: " << nx << " n: " << n-1 << endl;

        if (nv != n-1) dfs(graph, nv, n, nx);
        if (nv == n-1) ans = min(ans, nx);
    }

    // 単純パス
    seen[v] = false;
}

int main() {
    // 頂点数と辺数
    int n, m;
    cin >> n >> m;

    // グラフ
    Graph graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        a--; b--;

        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    seen.assign(n, false);
    // O(N+M)
    dfs(graph, 0, n, 0);

    cout << ans << endl;

    // for (int i = 0; i < graph.size(); i++) {
    //     cout << i << ": { ";
    //     for (int j = 0; j < graph[i].size(); j++) {
    //         cout << graph[i][j].to << " ";
    //     }
    //     cout << "}" << endl;
    // }
    return 0;
}