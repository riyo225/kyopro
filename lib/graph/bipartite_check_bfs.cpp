#include <bits/stdc++.h>
using namespace std;

// --- template.cpp ---
using Graph = vector<vector<long long>>;

// BFSを用いた二部グラフ判定
// 無向グラフが二部グラフであるかを判定します。
// 各頂点の距離の偶奇を色として利用します。
//
// @param n          : グラフの頂点数
// @param graph      : グラフ (隣接リスト形式)
// @return           : グラフが二部グラフであれば true, そうでなければ false
//
// 計算量:
//   - 時間計算量: O(V + E) (各頂点と各辺を一度だけ訪問するため)
//   - 空間計算量: O(V + E) (dist配列、キュー、グラフの隣接リストのため)
//
// 備考:
//   - 非連結グラフにも対応しています（全ての連結成分を走査します）。
//   - `dist` 配列が訪問済みフラグと色（距離の偶奇）を兼ねています。
//
bool is_bipartite_bfs(const Graph& graph, long long n) {
    vector<long long> dist(n, -1);
    queue<long long> que;

    bool is_graph_bipartite = true;

    for (long long i = 0; i < n; i++) {
        if (dist[i] != -1) continue;

        dist[i] = 0;
        que.push(i);

        while (!que.empty()) {
            long long v = que.front();
            que.pop();

            for (long long nv : graph[v]) {
                if (dist[nv] == -1) {
                    dist[nv] = dist[v] + 1;
                    que.push(nv);
                } else {
                    if (dist[v] % 2 == dist[nv] % 2) {
                        is_graph_bipartite = false;
                    }
                }
            }
        }
    }
    return is_graph_bipartite;
}