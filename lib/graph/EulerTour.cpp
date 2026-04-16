// [prefix: et]

struct Edge { ll to; ll cost; };
using WGraph = vector<vector<Edge>>;

struct EulerTour {
    vector<ll> in, out, tour;
    ll timer;

    EulerTour(const Graph& G, ll root = 0) {
        ll N = G.size();
        in.assign(N, -1);
        out.assign(N, -1);
        tour.assign(N, -1);
        timer = 0;

        auto dfs = [&](auto self, ll v, ll p) -> void {
            in[v] = timer;
            tour[timer] = v;
            timer++;

            for (const auto& e : G[v]) {
                if (e.to != p) {
                    self(self, e.to, v);
                }
            }

            out[v] = timer;
        };

        if (N > 0) dfs(dfs, root, -1);
    }

    // 頂点 v の部分木に対応する配列上の範囲 [l, r) を返す
    pll get_subtree_range(llg v) const {
        return {in[v], out[v]};
    }
};