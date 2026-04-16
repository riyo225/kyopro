#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr ll INF = (1LL << 60);

struct Edge
{
    int to;
    int cost;
    int silver;
};

using Graph = vector<vector<Edge>>;

using Tuple = tuple<ll, int, int>;

void Dijkstra(const Graph& graph, vector<vector<ll>>& dist, int startIndex, int startSilver, vector<int>& c, vector<int>& d)
{
    priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;
    pq.emplace((dist[startIndex][startSilver] = 0), startIndex, startSilver);

    while (!pq.empty())
    {
        // スタート地点から現在地までの距離と現在地のindex
        const ll dis = get<0>(pq.top());
        const int idx = get<1>(pq.top());
        const int sil = get<2>(pq.top());
        pq.pop();
        
        // 最短距離でなければスキップ
        if (dis > dist[idx][sil])
        {
            continue;
        }

        // 現在地からいけるすべての点について、distの更新を行い、pqに追加する
        for (const auto& edge : graph[idx])
        {
            const ll distance = (dis + edge.cost);

            if (dis + edge.cost < dist[edge.to][sil - edge.silver])
            {
                if (sil - edge.silver >= 0)
                {
                    pq.emplace((dist[edge.to][sil - edge.silver] = distance), edge.to, sil - edge.silver);
                }
            }
        }
        // 銀貨を補充する
        const int s = sil + c[idx];
        const int nd = dis + d[idx];
        if (s < 2500 && nd < dist[idx][s]) {
            dist[idx][s] = nd;
            pq.emplace(nd, idx, s);
        }
    }
}

int main() {
    ll v, e, s;
    cin >> v >> e >> s;

    if (s >= 2500) {
        s = 2500;
    }

    Graph graph(v);
    for (int i = 0; i < e; i++) {
        int s, t, a, b;
        cin >> s >> t >> a >> b;

        // 地点が0indexの場合は、s-1, t-1にする
        s--; t--;
        graph[s].push_back({ t, b, a });
        // 双方向の移動が必要な場合
        graph[t].push_back({ s, b, a });
    }

    vector<int> c(v);
    vector<int> d(v);

    for (int i = 0; i < v; i++) {
        cin >> c[i] >> d[i];
    }

    vector<vector<ll>> dist(v, vector<ll> (2509, INF));
    // グラフ, スタート地点からの距離を記録する配列, スタート地点のindex
    Dijkstra(graph, dist, 0, s, c, d);

    for (int i = 1; i < v; i++) {
        ll ans = INF;
        for (int j = 0; j < 2509; j++) {
            ans = min(ans, dist[i][j]);
        }
        cout << ans << endl;
    }

    
    return 0;
}