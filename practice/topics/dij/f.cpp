// https://atcoder.jp/contests/iroha2019-day2/tasks/iroha2019_day2_g
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

void Dijkstra(const Graph& graph, vector<vector<ll>>& dist, int startIndex, vector<ll>& x, vector<ll>& y, ll k)
{
    priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;
    pq.emplace((dist[startIndex][0] = 0), startIndex, 0);
    

    while (!pq.empty())
    {
        // スタート地点から現在地までの距離と現在地のindex
        const ll d = get<0>(pq.top());
        const int idx = get<1>(pq.top());
        const int cr_fl = get<2>(pq.top()); 
        pq.pop();

        // if (d >= 300) {
        //     cout << "現在地: " << d << " " << idx << " " << cr_fl << endl;
        //     cout << dist[idx][cr_fl] << endl;
        //     // キューの内容を出力（デバッグ用）
        //     cout << "Priority Queue State:\n";
        //     vector<Tuple> debug_pq;
        //     while (!pq.empty()) {
        //         debug_pq.push_back(pq.top());
        //         pq.pop();
        //     }
        //     for (const auto& elem : debug_pq) {
        //         cout << "(dist: " << get<0>(elem) << ", idx: " << get<1>(elem) << ", cr_fl: " << get<2>(elem) << ")\n";
        //     }
        //     cout << "------------------\n";

        //     // 再度キューに戻す
        //     for (const auto& elem : debug_pq) {
        //         pq.push(elem);
        //     }
        // }

        // 最短距離でなければ処理しない（逆走対策）
        if (d > dist[idx][cr_fl])
        {
            continue;
        }

        // 現在地からいけるすべての点について、distの更新を行い、pqに追加する
        for (const auto& edge : graph[idx])
        {
            // 縦移動
            const ll dis = (dist[idx][cr_fl] + edge.cost);

            if (dis < dist[edge.to][cr_fl])
            {
                pq.emplace((dist[edge.to][cr_fl] = dis), edge.to, cr_fl);
            }

            if (cr_fl >= k) {
                continue;
            }
        }

        // 横移動
        // cout << "cr_fl + x[idx]: " << cr_fl + x[idx] << endl;
        if (cr_fl + x[idx] >= k) {
            if (dist[idx][k] > dist[idx][cr_fl] + y[idx]) {
                pq.emplace((dist[idx][k] = dist[idx][cr_fl] + y[idx]), idx, k);
            }
            continue;
        }
        if (dist[idx][cr_fl + x[idx]] > dist[idx][cr_fl] + y[idx]) {
            pq.emplace((dist[idx][cr_fl + x[idx]] = dist[idx][cr_fl] + y[idx]), idx, cr_fl + x[idx]);
        }

    }
}

int main() {
    // 頂点数, 辺の数, スタート地点のindex
    ll v, e, k;
    cin >> v >> e >> k;

    Graph graph(v);
    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;

        // 地点が0indexの場合は、s-1, t-1にする
        s--; t--;
        graph[s].push_back({ t, d });
        graph[t].push_back({ s, d });
    }

    vector<ll> x(v);
    vector<ll> y(v);

    for (int i = 0; i < v; i++) {
        cin >> x[i] >> y[i];
    }

    vector<vector<ll>> dist(v, vector<ll> (k+1, INF));
    // グラフ, スタート地点からの距離を記録する配列, スタート地点のindex
    Dijkstra(graph, dist, 0, x, y, k);

    if (dist[v-1][k] == INF) {
        cout << -1 << endl;
    }
    else {
        cout << dist[v-1][k] << endl;
    }

    // for (int i = 0; i < v; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         if (dist[i][j] == INF) {
    //             cout << -1 << " ";
    //         }
    //         else {
    //             cout << dist[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    
    return 0;
}