// https://atcoder.jp/contests/abc035/tasks/abc035_d
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
    ll v, e, t;
    cin >> v >> e >> t;

    vector<ll> a(v);

    for (int i = 0; i < v; i++) {
        cin >> a[i];
    } 

    Graph graph1(v);
    Graph graph2(v);
    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;

        // 地点が1indexの場合は、s-1, t-1にする
        s--; t--;
        graph1[s].push_back({ t, d });
        // 双方向の移動が必要な場合
        graph2[t].push_back({ s, d });
    }

    vector<ll> dist1(v, INF);
    vector<ll> dist2(v, INF);
    // グラフ, スタート地点からの距離を記録する配列, スタート地点のindex
    Dijkstra(graph1, dist1, 0);
    Dijkstra(graph2, dist2, 0);
    
    // for (int i = 0; i < v; i++) {
    //     cout << dist1[i] << endl;
    // }

    // for (int i = 0; i < v; i++) {
    //     cout << dist2[i] << endl;
    // }

    ll ans = 0;
    for (int i = 0; i < v; i++) {
        if ((dist1[i] == INF) || (dist2[i] == INF))
		{
			continue;
		}
        ans = max(ans, (t - (dist1[i] + dist2[i]))*a[i]);
    }
    
    cout << ans << endl;

    return 0;
}