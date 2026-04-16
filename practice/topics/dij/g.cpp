// https://atcoder.jp/contests/wupc2012/tasks/wupc2012_5
// また，道の途中で引き返したり，街や道の途中で休憩を取ることはできない．って条件式を見逃してたよ～
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

using Tuple = tuple<ll, int, int>;

void Dijkstra(const Graph& graph, vector<vector<ll>>& dist, int startIndex, int div, int n)
{
    priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;
    pq.emplace((dist[startIndex][0] = 0), startIndex, 0);

    while (!pq.empty())
    {
        // スタート地点から現在地までの距離と現在地のindex
        const ll dis = get<0>(pq.top());
        const int idx = get<1>(pq.top());
        const int rem = get<2>(pq.top());
        pq.pop();
        
        // 最短距離でなければスキップ
        if (dis > dist[idx][rem])
        {
            continue;
        }

        if (idx == n - 1) {
            continue;
        }
        // 現在地からいけるすべての点について、distの更新を行い、pqに追加する
        for (const auto& edge : graph[idx])
        {
            const ll distance = dis + edge.cost;

            int new_rem = (rem + edge.cost) % div;

            if (distance < dist[edge.to][new_rem]) {
                pq.emplace((dist[edge.to][new_rem] = distance), edge.to, new_rem);
            }
        }
    }
}

int main() {
    ll v, e;
    cin >> v >> e;

    Graph graph(v);
    for (int i = 0; i < e; i++) {
        int s, t, a;
        cin >> s >> t >> a;

        graph[s].push_back({ t, a });
        graph[t].push_back({ s, a });
    }

    vector<vector<ll>> dist(v, vector<ll> (28, INF));
    // グラフ, スタート地点からの距離を記録する配列, スタート地点のindex
    Dijkstra(graph, dist, 0, 28, v);

    ll ans = INF;
    for (int i = 0; i < 28; i++) {
        if (i % 4 == 0 || i % 7 == 0) {
            ans = min(ans, dist[v-1][i]);
        }
    }

    cout << ans << endl;

    return 0;
}