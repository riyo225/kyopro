#include <bits/stdc++.h>
using namespace std;

// --- template.cpp ---
using Graph = vector<vector<long long>>;

// トポロジカルソート (Kahnのアルゴリズム - 入次数を使用)
// 有向非巡回グラフ (DAG) の頂点をトポロジカル順序で並べる
//
// @param n          : グラフの頂点数
// @param graph_param: グラフ (隣接リスト形式、有向グラフ)
// @return           : トポロジカル順序に並んだ頂点リスト。
//                     もしグラフにサイクルがあれば (DAGでない場合)、リストのサイズはnより小さい。
//
// 計算量:
//   - 時間計算量: O(V + E) (各頂点と各辺を一度だけ処理するため)
//   - 空間計算量: O(V + E) (deg配列、キュー、order配列、グラフ隣接リストのため)
//
// 備考:
//   - 入次数が0の頂点から開始します。
//   - 複数のトポロジカル順序が存在する場合、どれが返されるかは、キューへの追加順序に依存します。
//   - グラフにサイクルがある場合、返されるリストのサイズは `n` よりも小さくなります。
//
vector<long long> topological_sort_kahn(const Graph& graph, long long n) {
    // 各頂点の入次数を計算
    vector<long long> deg(n, 0);
    for (long long u = 0; u < n; u++) {
        for (long long v : graph[u]) {
            deg[v]++;
        }
    }

    queue<long long> que;

    for (long long i = 0; i < n; i++) {
        if (deg[i] == 0) {
            que.push(i);
        }
    }

    vector<long long> order;

    while (!que.empty()) {
        long long v = que.front();
        que.pop();
        order.push_back(v);

        for (long long nv : graph[v]) {
            deg[nv]--;

            if (deg[nv] == 0) {
                que.push(nv);
            }
        }
    }
    return order;
}
