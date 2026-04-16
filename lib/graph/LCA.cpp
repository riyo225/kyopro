// [prefix: lca]

struct Edge { long long to; long long cost; };
using WGraph = vector<vector<Edge>>;

// 重み付木の LCA 重みがないときは重み 1 として計算する
struct LCA {
    long long N, K;
    vector<vector<long long>> par;
    vector<long long> depth;
    vector<long long> dist_root;

    LCA(const vector<vector<Edge>>& G, long long root = 0) {
        N = G.size();
        K = 1;
        while ((1 << K) < N) K++;

        par.assign(K, vector<long long> (N, -1));
        depth.assign(N, -1);
        dist_root.assign(N, 0);

        dfs(G, root, -1, 0, 0);

        for (long long k = 0; k < K - 1; k++) {
            for (long long v = 0; v < N; v++) {
                if (par[k][v] < 0) {
                    par[k + 1][v] = -1;
                }
                else {
                    par[k + 1][v] = par[k][par[k][v]];
                }
            }
        }
    }

    void dfs(const vector<vector<Edge>>& G, long long v, long long p, long long d, long long cur_dist) {
        par[0][v] = p;
        depth[v] = d;
        dist_root[v] = cur_dist;
        for (auto e : G[v]) {
            if (e.to != p) {
                dfs(G, e.to, v, d + 1, cur_dist + e.cost);
            }
        }
    }

    long long get_ancestor(long long u, long long k) {
        for (long long i = 0; i < K; i++) {
            if ((k >> i) & 1) {
                u = par[i][u];
                if (u == -1) return -1;
            }
        }
        return u;
    }

    long long get(long long u, long long v) {
        if (depth[u] < depth[v]) swap(u, v);

        long long diff = depth[u] - depth[v];
        u = get_ancestor(u, diff);

        if (u == v) return u;

        for (long long k = K - 1; k >= 0; k--) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }

        return par[0][u];
    }

    long long dist(long long u, long long v) {
        return dist_root[u] + dist_root[v] - 2 * dist_root[get(u, v)];
    }
};