#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr ll INF = (1LL << 60);

struct Edge
{
    int to;
    int cost;
    char label;
};

using Graph = vector<vector<Edge>>;

using Pair = pair<ll, int>;

void Dijkstra(const Graph& graph, vector<ll>& dist, int startIndex, int targetIndex, vector<int>& path)
{
    // 直前の頂点を記録する配列
    vector<int> p(dist.size(), -1);

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.emplace((dist[startIndex] = 0), startIndex);

    while (!pq.empty())
    {
        // スタート地点から現在地までの距離と現在地のindex
        const ll d = pq.top().first;
        const int idx = pq.top().second;
        pq.pop();

        // 最短距離でなければ処理しない（逆走対策）
        if (d > dist[idx])
        {
            continue;
        }

        // 現在地からいけるすべての点について、distの更新を行い、pqに追加する
        for (const auto& edge : graph[idx])
        {
            const ll distance = (dist[idx] + edge.cost);

            if (distance < dist[edge.to])
            {
                // 直前の頂点を記録する
                p[edge.to] = idx;
                
                pq.emplace((dist[edge.to] = d), edge.to);
            }
        }
    }

    if (dist[targetIndex] != INF) {
        for (int i = targetIndex; i != -1; i = p[i]) {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
    }
}

int main() {
    // 頂点数, 辺の数, スタート地点のindex
    ll n;
    cin >> n;

    Graph graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            if (x != '-') {
                graph[i].push_back({ j, x });
            }
        }
    }

    vector<ll> dist(n, INF);
    // グラフ, スタート地点からの距離を記録する配列, スタート地点のindex
    Dijkstra(graph, dist, r);

    for (int i = 0; i < v; i++) {
        if (dist[i] == INF) {
            cout << "INF" << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }
    
    return 0;
}