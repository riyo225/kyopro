#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<long long>>;

// --- グローバル変数 ---
vector<bool> seen;
vector<bool> finished;
long long cycle_start_node;
stack<long long> hist;

bool cycle_dfs(const Graph& graph, long long v, long long p) {
    seen[v] = true;
    hist.push(v);

    for (long long nv : graph[v]) {
        if (nv == p) continue;
        if (finished[nv]) continue;

        if (seen[nv]) {
            cycle_start_node = nv;
            return true;
        }

        if (cycle_dfs(graph, nv, v)) {
            return true;
        }
    }

    hist.pop();
    finished[v] = true;
    return false;
}
