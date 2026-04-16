#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<long long>>;

// --- グローバル変数 ---
// 各ノードの深さ
vector<long long> depth;
// 各ノードの親
vector<long long> parent;
// 各ノードが根となる部分木のサイズ
vector<long long> subtree_size;

// O(V)
void dfs_tree(const Graph& graph, long long v, long long p, long long depth_current) {
    depth[v] = depth_current;
    parent[v] = p;
    subtree_size[v] = 1;

    for (long long nv : graph[v]) {
        if (nv == p) continue;

        dfs_tree(graph, nv, v, depth_current + 1);

        subtree_size[v] += subtree_size[nv];
    }
}

void run_dfs_tree(const Graph& graph, long long n, long long start_node) {
    // --- 初期化 ---
    depth.assign(n, 0);
    parent.assign(n, -1);
    subtree_size.assign(n, 0);

    
    dfs_tree(graph, start_node, -1, 0);
}