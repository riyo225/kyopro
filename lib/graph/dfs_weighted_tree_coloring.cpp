#include <bits/stdc++.h>
using namespace std;

struct Edge { long long to; long long cost; };
using Graph = std::vector<std::vector<Edge>>;

// --- グローバル変数 ---
// -1: 未訪問
//  0: 白
//  1: 黒
vector<long long> color;

// O(V + E)
void dfs_weighted_tree_coloring_internal(const Graph& graph, long long v, long long c) {
    color[v] = c;

    for (const auto& edge : graph[v]) {
        long long nv = edge.to;
        long long cost = edge.cost;

        if (color[nv] != -1) continue;

        // 辺の重みが偶数なら同じ色、奇数なら異なる色
        if (cost % 2 == 0) {
            dfs_weighted_tree_coloring_internal(graph, nv, c);
        } else{
            dfs_weighted_tree_coloring_internal(graph, nv, 1 - c);
        }
    }
}

void run_dfs_weighted_tree_coloring(const Graph& graph, long long n, long long start_node, long long initial_color) {
    // --- 初期化 ---
    color.assign(n, -1); 

    dfs_weighted_tree_coloring_internal(graph, start_node, initial_color);
}