// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0212
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

using Tuple = tuple<ll, int, int>;

void Dijkstra(const Graph& graph, vector<vector<ll>>& dist, int startIndex, int startTicket)
{
    priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;
    pq.emplace((dist[startIndex][startTicket] = 0), startIndex, startTicket);

    while (!pq.empty())
    {
        // スタート地点から現在地までの距離と現在地のindex
        const ll dis = get<0>(pq.top());
        const int idx = get<1>(pq.top());
        const int ti = get<2>(pq.top());
        pq.pop();
        
        // 最短距離でなければスキップ
        if (dis > dist[idx][ti])
        {
            continue;
        }

        // 現在地からいけるすべての点について、distの更新を行い、pqに追加する
        for (const auto& edge : graph[idx])
        {
            const ll distance1 = (dis + edge.cost);
            const ll distance2 = (dis + edge.cost/2);

            if (distance1 < dist[edge.to][ti])
            {
                pq.emplace((dist[edge.to][ti] = distance1), edge.to, ti);
                
            }

            if (ti > 0) {
                if (distance2 < dist[edge.to][ti-1])
                {
                    pq.emplace((dist[edge.to][ti-1] = distance2), edge.to, ti-1);
                    
                }
            }
        }
    }
}

int main() {
    int c;
    ll v, e;
    int s, d;
    cin >> c >> v >> e >> s >> d;
    s--; d--;
    Graph graph(v);
    for (int i = 0; i < e; i++) {
        int s, t, a;
        cin >> s >> t >> a;

        // 地点が0indexの場合は、s-1, t-1にする
        s--; t--;
        graph[s].push_back({ t, a });
        // 双方向の移動が必要な場合
        graph[t].push_back({ s, a });
    }

    vector<vector<ll>> dist(v, vector<ll> (c+1, INF));
    // グラフ, スタート地点からの距離を記録する配列, スタート地点のindex
    Dijkstra(graph, dist, s, c);

    // for (int i = 0; i < v; i++) {
    //     for (int j = 0; j < c+1; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = INF;
    for (int i = 0; i < c+1; i++) {
        ans = min(ans, dist[d][i]);
    }
    cout << ans << endl;

    return 0;
}