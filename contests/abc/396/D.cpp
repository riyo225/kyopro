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

using Pair = pair<ll, ll>;

int main() {
    // 頂点数と辺数
    int n, m;
    cin >> n >> m;

    Graph graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        // 問題文が1indexなら
        a--; b--;
        graph[b].push_back({ a, c });
        // 双方向の移動が必要な場合
        graph[a].push_back({ b, c });
    }

    vector<ll> dist(n, INF);
    queue<int> que;

    // 初期条件（頂点０を開始地点とする）
    dist[0] = 0;
    que.push(0);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        cout << "------" << v << "-------" << endl;
        // vから辿れる頂点をすべて調べる
        for (const auto& edge : graph[v]) {
            int nv = edge.to;
            ll d = edge.cost;

            ll new_xor = dist[v] ^ d;
            dist[nv] = min(dist[nv], new_xor);
            cout << dist[v] << "^" << d << "=" << new_xor << endl;
            if (nv != n) {
                que.push(nv);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}