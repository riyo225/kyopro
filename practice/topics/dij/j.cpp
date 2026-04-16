// https://atcoder.jp/contests/abc387/tasks/abc387_d
#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr ll INF = (1LL << 60);

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

using IdxPair = pair<int, int>;
using Pair = pair<ll, IdxPair>;

void Dijkstra(vector<vector<ll>>& graph, vector<vector<ll>>& dist, int startX, int startY, int h, int w)
{
    vector<vector<IdxPair>> p(h, vector<IdxPair> (w, IdxPair(-1, -1)));

    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.emplace((dist[startX][startY] = 0), IdxPair(startX, startY));

    while (!pq.empty())
    {
        // スタート地点から現在地までの距離と現在地のindex
        const ll d = pq.top().first;
        const int vx = pq.top().second.first;
        const int vy = pq.top().second.second;
        pq.pop();

        // 最短距離でなければ処理しない（逆走対策）
        if (d > dist[vx][vy])
        {
            continue;
        }

        // 現在地からいけるすべての点について、distの更新を行い、pqに追加する
        for (int i = 0; i < 4; i++) 
        {
            int nx, ny;
            nx = vx + dx[i], ny = vy + dy[i];
            // 移動先が範囲外ならとばす
            if (nx < 0 || ny < 0 || nx >= h || ny >= w)
            {
                continue;
            }
            const ll distance = graph[nx][ny] + d;
            // これなに
            if (distance < dist[nx][ny])
            {
                p[nx][ny] = IdxPair(vx, vy);

                pq.emplace((dist[nx][ny] = distance), IdxPair(nx, ny));
            }
        }
    }
}

int main() {
    // 行, 列
    int h, w;
    cin >> h >> w;

    // dist[x][y] = cost;
    vector<vector<ll>> graph(h, vector<ll> (w, INF));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> graph[i][j];
        }
    }

    vector<vector<ll>> dist(h, vector<ll> (w, INF));
    vector<vector<ll>> dist1(h, vector<ll> (w, INF));
    vector<vector<ll>> dist2(h, vector<ll> (w, INF));

    // グラフ, スタート地点からの距離を記録する配列, スタート地点のindex
    Dijkstra(graph, dist, h-1, 0, h, w);
    Dijkstra(graph, dist1, h-1, w-1, h, w); 
    Dijkstra(graph, dist2, 0, w-1, h, w);   

    ll a = INF;
    int b, c;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            a = min(a, dist[i][j] + dist1[i][j] + dist2[i][j] - 2 * graph[i][j]);
        }
    }
    cout << a << endl;

    return 0;
}