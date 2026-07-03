// [prefix: toposort]

struct TopoSort {
    bool is_dag, is_unique;
    vector<ll> res;
    vector<ll> indeg;

    // flag = true: priority_queue, flag = false: queue
    TopoSort (const Graph& G, bool flag = false) {
        ll n = G.size();
        indeg.assign(n, 0);
        
        for (ll v = 0; v < n; v++) {
            for (ll nv : G[v]) {
                indeg[nv]++;
            }
        }

        is_unique = true;

        if (flag) {
            priority_queue<ll, vector<ll>, greater<ll>> pq;
            for (ll i = 0; i < n; i++) {
                if (indeg[i] == 0) pq.push(i);
            }

            while (!pq.empty()) {
                if (pq.size() > 1) is_unique = false;

                ll v = pq.top();
                res.push_back(v);
                pq.pop();

                for (ll nv : G[v]) {
                    indeg[nv]--;
                    if (indeg[nv] == 0) pq.push(nv);
                }
            }
            
        }
        else {
            queue<ll> que;
            for (ll i = 0; i < n; i++) {
                if (indeg[i] == 0) que.push(i);
            }

            while (!que.empty()) {
                if (que.size() > 1) is_unique = false;

                ll v = que.front();
                res.push_back(v);
                que.pop();

                for (ll nv : G[v]) {
                    indeg[nv]--;
                    if (indeg[nv] == 0) que.push(nv);
                }
            }
        }

        is_dag = (res.size() == n);
        if (!is_dag) res.clear();
    }
};