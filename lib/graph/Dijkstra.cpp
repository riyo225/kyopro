// [prefix: dijkstra]

vector<ll> dijkstra(const Graph& G, ll s) {
    vector<ll> dist(G.size(), INF);
    using P = pair<ll, ll>;
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d > dist[v]) continue;

        for (const auto& [nv, c] : G[v]) {
            if (dist[nv] > dist[v] + c) {
                dist[nv] = dist[v] + c;
                pq.push({dist[nv], nv});
            }
        }
    }
    return dist;
}