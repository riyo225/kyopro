#include <bits/stdc++.h>
using namespace std;

// --- template.cpp ---
using Graph = vector<vector<long long>>;

// --- グローバル変数 ---
// -1: 未訪問
//  0: 白
//  1: 黒
vector<long long> color;

// O(V + E)
bool is_bipartite_dfs(const Graph& graph, long long v, long long c) {
    color[v] = c;
    
    for (long long nv : graph[v]) {
        if (color[nv] != -1) {
            if (color[nv] == c) {
                return false;
            }
            continue;
        }

        if (!is_bipartite_dfs(graph, nv, 1 - c)) {
            return false;
        }
    }
    return true;
}

// O(V + E)
bool run_bipartite_dfs(const Graph& graph, long long n) {
    color.assign(n, -1);

    for (long long i = 0; i < n; i++) {
        if (color[i] != -1) continue;

        if (!is_bipartite_dfs(graph, i, 1)) {
            return false;
        }
    }
    return true;
}