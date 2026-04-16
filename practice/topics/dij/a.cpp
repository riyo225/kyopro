// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
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

void Dijkstra(const Graph& graph, vector<ll>& dist, int startIndex, int targetIndex, vector<int>& path)
{
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
            const ll d = (dist[idx] + edge.cost);

            if (d < dist[edge.to])
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
    ll v, e, r;
    cin >> v >> e >> r;

    Graph graph(v);
    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s].push_back({ t, d });
    }

    vector<ll> dist(v, INF);
    vector<int> path;
    Dijkstra(graph, dist, r, v-1, path);

    for (int i = 0; i < v; i++) {
        if (dist[i] == INF) {
            cout << "INF" << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    
    return 0;
}