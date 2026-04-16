#include <bits/stdc++.h>
using namespace std;

// --- template.cpp ---
using Graph = vector<vector<long long>>;

long long bfs(const Graph& graph, long long n, long long start_node) {
    vector<long long> dist(n, -1);
    queue<long long> que;

    long long component_count = 0;

    for (long long i = 0; i < n; i++) {
        if (dist[i] == -1) {
            dist[i] = 0;
            que.push(i);
            component_count++;

            while (!que.empty()) {
                long long v = que.front();
                que.pop();

                for (long long nv : graph[v]) {
                    if (dist[nv] == -1) {
                        dist[nv] = dist[v] + 1;
                        que.push(nv);
                    }
                }
            }
        }
    }
    return component_count;
}