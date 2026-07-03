vector<ll> dist(n, -1);
vector<ll> pre(n, -1);
queue<ll> que;

ll s = 0;
dist[s] = 0;
que.push(s);

while (!que.empty()) {
    ll v = que.front();
    que.pop();

    for (ll nv : graph[v]) {
        if (dist[nv] != -1) continue;

        dist[nv] = dist[v] + 1;
        pre[nv] = v;
        que.push(nv);
    }
}