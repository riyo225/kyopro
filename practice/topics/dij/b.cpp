// https://atcoder.jp/contests/typical90/tasks/typical90_m
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
            const ll distance = (dist[idx] + edge.cost);

            if (distance < dist[edge.to])
            {
                pq.emplace((dist[edge.to] = distance), edge.to);
            }
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;

    Graph graph(n);
    for (int i = 0; i < m; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s-1].push_back({ t-1, d });
        graph[t-1].push_back({ s-1, d });
    }

    vector<ll> dist1(n, INF);
    vector<ll> dist2(n, INF);
    Dijkstra(graph, dist1, 0);
    Dijkstra(graph, dist2, n-1);

    for (int i = 0; i < n; i++) {
        cout << dist1[i] + dist2[i] << endl;
    }
    
    return 0;
}