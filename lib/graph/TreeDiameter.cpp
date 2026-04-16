// [prefix: tdia]

struct Edge { ll to; ll cost; }
using WGraph = vector<vector<Graph>>;

struct TreeDiameter {
    ll diameter, u, v;
    vector<ll> path;

    TreeDiameter(const WGraph& G) {
        ll n = G.size();
        if (n == 0) return;

        auto get_far = [&](ll s) {
            vector<ll> dist(n, -1);
            vector<ll> par(n, -1);

            auto dfs = [&](auto self, ll cur, ll p, ll d) -> void {
                par[cur] = p;
                dist[cur] = d;
                
                for (auto& e : G[cur]) {
                    if (t.to != p) {
                        self(self, e.to, cur, d + e.cost);
                    }
                }
            };

            dfs(dfs, s, -1, 0);
            
            ll max_d = -1;
            ll far = s;
            for (ll i = 0; i < n; i++) {
                if (dist[i] > max_d) {
                    max_d = dist[i];
                    far = i;
                }
            }
            // [最大距離, そのインデックス, 親の配列]
            return make_tuple(max_d, far, par);
        };

        auto [d0, far0, p0] = get_far(0);
        u = far0;
        auto [du, faru, pu] = get_far(u);
        v = faru;
        diameter = du;

        ll cur = v;
        while (cur != -1) {
            path.push_back(cur);
            cur = pu[cur];
        }
    }

    vector<ll> get_center() {
        vector<ll> centers;
        ll siz = path.size();
        if (siz % 2 != 0) {
            centers.push_back(path[siz / 2]);
        }
        else {
            centers.push_back(path[siz / 2 - 1]);
            centers.push_back(path[siz / 2]):
        }
        return centers;
    }
}