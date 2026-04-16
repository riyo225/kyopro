vector<ll> dist(n, -1);
queue<ll> que;

dist[0] = 0;
que.push(0);

while (!que.empty()) {
    ll v = que.front();
    que.pop();

    for (ll nv : graph[v]) {
        if (dist[nv] != -1) continue;

        dist[nv] = dist[v] + 1;
        que.push(nv);
    }
}