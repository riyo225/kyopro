// https://atcoder.jp/contests/abc164/tasks/abc164_e
#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr ll INF = (1LL << 60);

struct Edge
{
    int to;
    ll cost;
    bool flag;
};

using Graph = vector<vector<Edge>>;

using Tuple = tuple<ll, int, int>;

void Dijkstra(const Graph& graph, vector<vector<ll>>& dist, int startIndex, int startFlag, ll x)
{
    priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;
    pq.emplace((dist[startIndex][startFlag] = 0), startIndex, startFlag);

    while (!pq.empty())
    {
        // cout << "PQ 状態: ";
        // priority_queue<Tuple, vector<Tuple>, greater<Tuple>> tempPQ = pq;
        // while (!tempPQ.empty()) {
        //     auto [d, i, f] = tempPQ.top();
        //     tempPQ.pop();
        //     cout << "(距離: " << d << ", 頂点: " << i << ", フラグ: " << f << ") ";
        // }
        // cout << endl;
        // スタート地点から現在地までの距離と現在地のindex
        const ll dis = get<0>(pq.top());
        const int idx = get<1>(pq.top());
        const bool f = get<2>(pq.top());
        pq.pop();
        
        // 最短距離でなければスキップ
        if (dis > dist[idx][f])
        {
            continue;
        }

        // 現在地からいけるすべての点について、distの更新を行い、pqに追加する
        for (const auto& edge : graph[idx])
        {
            ll distance;
            if (f == edge.flag) {
                distance = (dis + edge.cost);
            }
            else {
                distance = (dis + edge.cost + x);
            }
            
            if (distance < dist[edge.to][edge.flag])
            {
                pq.emplace((dist[edge.to][edge.flag] = distance), edge.to, edge.flag);
            }
        }
    }
}

int main() {
    ll v, e, x;
    cin >> v >> e >> x;

    Graph graph(v);
    for (int i = 0; i < e; i++) {
        int s, t;
        cin >> s >> t;

        // 地点が0indexの場合は、s-1, t-1にする
        s--; t--;
        graph[s].push_back({ t, 1, true });
        // 双方向の移動が必要な場合
        graph[t].push_back({ s, 1, false });
    }

    vector<vector<ll>> dist(v, vector<ll> (2, INF));
    // グラフ, スタート地点からの距離を記録する配列, スタート地点のindex
    Dijkstra(graph, dist, 0, true, x);

    // for (int i = 1; i < v; i++) {
    //     for (int j = 0; j < 2; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = min(dist[v-1][0], dist[v-1][1]);
    cout << ans << endl;

    
    return 0;
}