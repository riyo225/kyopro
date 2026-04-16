// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_f
#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr ll INF = (1LL << 60);

struct Edge
{
    int to;
    int cost;
};

using Graph = vector<vector<Edge>>;

using Pair = pair<ll, int>;

void Dijkstra(const Graph& graph, vector<ll>& dist, int startIndex)
{
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
            const ll d = (dist[idx] + edge.cost);

            if (d < dist[edge.to])
            {
                pq.emplace((dist[edge.to] = d), edge.to);
            }
        }
    }
}

int main() {
    ll v, e;
    cin >> v >> e;

    Graph graph(v);
    for (int i = 0; i < e; i++) {
        int f;
        cin >> f;
        if (f == 0) {
            int st, go;
            vector<ll> dist(v, INF);
            cin >> st >> go;
            st--; go--;
            // グラフ, スタート地点からの距離を記録する配列, スタート地点のindex
            Dijkstra(graph, dist, st);
            
            if (dist[go] == INF) {
                cout << -1 << endl;
            }
            else {
                cout << dist[go] << endl;
            }
        }
        if (f == 1) {
            int s, t, d;
            cin >> s >> t >> d;
            s--; t--;
            graph[s].push_back({ t, d });
            graph[t].push_back({ s, d });
        }
    }
    
    return 0;
}