#include <bits/stdc++.h>
using namespace std;

#define ll long long
constexpr ll INF = (1LL << 60);

using Graph = vector<vector<int>>;

vector<bool> seen;
int ans = 0;
void dfs(const Graph& graph, int v, int k, int cnt) {
    seen[v] = true;
    cnt++;

    if (cnt == k) {
        ans++;
        cnt = 0;
    }

    for (auto nv : graph[v]) {
        if (seen[nv]) continue;
        dfs(graph, nv, k, cnt);
    }

    // 単純パス=各頂点は一度だけ通る
    // seen[v] = false;
}

int main() {
    int n, k;
    cin >> n >> k;

    // グラフ
    Graph graph(n*k);
    for (int i = 0; i < n*k; i++) {
        int a, b;
        cin >> a >> b;

        a--; b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    seen.assign(n*k, false);
    // O(N+M)
    dfs(graph, 0, k, 0);

    if (ans == n) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}