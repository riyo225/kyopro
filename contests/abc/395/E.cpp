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

using Pair = pair<ll, int>;
using Tuple = tuple<ll, int, bool>;

void PrintQueue(priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq) {
    cout << "=== Queue 状態 ===" << endl;
    vector<Tuple> temp;
    
    while (!pq.empty()) {
        Tuple t = pq.top();
        pq.pop();
        cout << "(距離: " << get<0>(t) << ", ノード: " << get<1>(t) << ", フラグ: " << get<2>(t) << ")" << endl;
        temp.push_back(t);
    }
    
    // 元のキューに戻す
    for (const auto& t : temp) {
        pq.push(t);
    }
}

void Dijkstra(const Graph& graph1, const Graph& graph2, vector<ll>& dist, int startIndex, ll x)
{
    priority_queue<Tuple, vector<Tuple>, greater<Tuple>> pq;
    pq.emplace((dist[startIndex] = 0), startIndex, true);

    while (!pq.empty())
    {

        // PrintQueue(pq);  // キューの状態を出力

        // スタート地点から現在地までの距離と現在地のindex
        const ll d = get<0>(pq.top());
        const int idx = get<1>(pq.top());
        bool f = get<2>(pq.top());
        pq.pop();

        // cout << "スタート地点から現在地までの距離: " << d << " 現在地のindex: " << idx << " フラグ: " << f << endl;

        // 最短距離でなければ処理しない（逆走対策）
        if (d > dist[idx])
        {
            continue;
        }
        
        for (const auto& edge : graph1[idx])
        {
            // cout << edge.cost << " " << edge.to << " " << endl;
            if (f) {
                ll d = (dist[idx] + edge.cost);
                if (d < dist[edge.to])
                {
                    pq.emplace((dist[edge.to] = d), edge.to, f);
                }
            }
            else {
                ll d = (dist[idx] + edge.cost + x);
                if (d < dist[edge.to])
                {

                    pq.emplace((dist[edge.to] = d), edge.to, !f);
                }
            }
        } 
        
        for (const auto& edge : graph2[idx])
        {
            if (!f) {
                ll d = (dist[idx] + edge.cost);
                if (d < dist[edge.to])
                {
                    pq.emplace((dist[edge.to] = d), edge.to, f);
                }
            }
            else {
                ll d = (dist[idx] + edge.cost + x);
                if (d < dist[edge.to])
                {
                    pq.emplace((dist[edge.to] = d), edge.to, !f);
                }
            }
        }
    }
}

int main() {
    // 頂点数, 辺の数, スタート地点のindex
    ll v, e, x;
    cin >> v >> e >> x;

    Graph graph1(v);
    Graph graph2(v);
    for (int i = 0; i < e; i++) {
        int s, t;
        cin >> s >> t;

        // 地点が0indexの場合は、s-1, t-1にする
        s--; t--;
        graph1[s].push_back({ t, 1, });
        // 双方向の移動が必要な場合
        graph2[t].push_back({ s, 1, });
    }

    vector<ll> dist(v, INF);
    // グラフ, スタート地点からの距離を記録する配列, スタート地点のindex
    Dijkstra(graph1, graph2, dist, 0, x);

    cout << dist[v-1] << endl;

    // for (int i = 0; i < graph.size(); i++) {
    //     for (int j = 0; j < graph[i].size(); j++) {
    //         cout << "~~~~~~" << i+1 << "~~~~~~~" << endl;
    //         cout << "cost: " << graph[i][j].cost << " to: " << graph[i][j].to+1 << endl;
    //     }
    // }
    
    return 0;
}