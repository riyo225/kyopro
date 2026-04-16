#include <bits/stdc++.h>
using namespace std;

int n, m;
int u[200009], v[200009], w[200009];
vector<pair<int, int>> g[200009];
bool visited[200009];
long long ans[200009];

void dfs(int pos) {
    visited[pos] = true;
    for (int i = 0; i < g[pos].size(); i++){
        int nex = g[pos][i].first;
        int value = g[pos][i].second;
        ans[nex] = ans[pos] + value;
        if (!visited[nex]) dfs(nex);
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        g[u[i]].push_back(make_pair(v[i], w[i]));
        g[v[i]].push_back(make_pair(u[i], -w[i]));
    }

    for (int i = 1; i <= n; i++) visited[i] = false;

    ans[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}